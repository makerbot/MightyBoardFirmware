/*
 * Copyright 2010 by Adam Mayer	 <adam@makerbot.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
 
#include "Host.hh"
#include "Command.hh"
#include <string.h>
#include "Commands.hh"
#include "Steppers.hh"
#include "Planner.hh"
#include "DebugPacketProcessor.hh"
#include "Timeout.hh"
#include "Version.hh"
#include <util/atomic.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include "Main.hh"
#include "Errors.hh"
#include "Eeprom.hh"
#include "EepromMap.hh"
#include "UtilityScripts.hh"

namespace host {

/// Identify a command packet, and process it.  If the packet is a command
/// packet, return true, indicating that the packet has been queued and no
/// other processing needs to be done. Otherwise, processing of this packet
/// should drop through to the next processing level.
bool processCommandPacket(const InPacket& from_host, OutPacket& to_host);
bool processQueryPacket(const InPacket& from_host, OutPacket& to_host);
bool processExtruderQueryPacket(const InPacket& from_host, OutPacket& to_host);

// Timeout from time first bit recieved until we abort packet reception
Timeout packet_in_timeout;
Timeout cancel_timeout;

#define HOST_PACKET_TIMEOUT_MS 20
#define HOST_PACKET_TIMEOUT_MICROS (1000L*HOST_PACKET_TIMEOUT_MS)

//#define HOST_TOOL_RESPONSE_TIMEOUT_MS 50
//#define HOST_TOOL_RESPONSE_TIMEOUT_MICROS (1000L*HOST_TOOL_RESPONSE_TIMEOUT_MS)

char machineName[eeprom_info::MAX_MACHINE_NAME_LEN];

char buildName[MAX_FILE_LEN];

uint32_t buildSteps;

/// Used to indicate what the UI should do, and used by
/// host process to know what state it's in for error/command allowed.
/// doesn't change state machine per-se, but sets context for other cmds.
HostState currentState;

bool do_host_reset = false;
bool hard_reset = false;

void runHostSlice() {
		bool cancelBuild = false;
        InPacket& in = UART::getHostUART().in;
        OutPacket& out = UART::getHostUART().out;
	if (out.isSending()) {
		// still sending; wait until send is complete before reading new host packets.
		return;
	}
    // after cancel print, try to send a msg to repG that print has been canceled
    // timeout if this is not possible and reset the bot
	if(cancel_timeout.isActive() && !(cancel_timeout.hasElapsed())){
		cancelBuild = true;
		cancel_timeout = Timeout();
		_delay_us(500000);
	}
    // soft reset the machine unless waiting to notify repG that a cancel has occured
	if (do_host_reset && !cancelBuild){
		
		do_host_reset = false;


		// reset local board
		reset(hard_reset);
		
        // hard_reset can be called, but is not called by any
        // a hard reset calls the start up sound and resets heater errors
		hard_reset = false;
		packet_in_timeout.abort();

		// Clear the machine and build names
		machineName[0] = 0;
		buildName[0] = 0;
		currentState = HOST_STATE_READY;
			
		return;
	}
    // new packet coming in
	if (in.isStarted() && !in.isFinished()) {
		if (!packet_in_timeout.isActive()) {
			// initiate timeout
			packet_in_timeout.start(HOST_PACKET_TIMEOUT_MICROS);
		} else if (packet_in_timeout.hasElapsed()) {
			in.timeout();
		}
	}
	if (in.hasError()) {
		// Reset packet quickly and start handling the next packet.
		// Report error code.
		if (in.getErrorCode() == PacketError::PACKET_TIMEOUT) {
             Motherboard::getBoard().indicateError(ERR_HOST_PACKET_TIMEOUT);
		} else{
             Motherboard::getBoard().indicateError(ERR_HOST_PACKET_MISC);
		}
		in.reset();
	}
	if (in.isFinished()) {
		packet_in_timeout.abort();
		out.reset();
	  // do not respond to commands if the bot has had a heater failure
		if(currentState == HOST_STATE_HEAT_SHUTDOWN){
			out.append8(RC_CMD_UNSUPPORTED);
		}else if(cancelBuild){
			out.append8(RC_CANCEL_BUILD);
			cancelBuild = false;
			Motherboard::getBoard().indicateError(6);
		} else
#if defined(HONOR_DEBUG_PACKETS) && (HONOR_DEBUG_PACKETS == 1)
		if (processDebugPacket(in, out)) {
			// okay, processed
		} else
#endif
		if (processCommandPacket(in, out)) {
			// okay, processed
		} else if (processQueryPacket(in, out)) {
			// okay, processed
		} else {
			// Unrecognized command
			out.append8(RC_CMD_UNSUPPORTED);
		}
		in.reset();
                UART::getHostUART().beginSend();
	}
    /// mark new state as ready if done building from SD
	if(currentState==HOST_STATE_BUILDING_FROM_SD)
	{
		if(!sdcard::isPlaying())
			currentState = HOST_STATE_READY;
	}
    // mark new state as ready if done buiding onboard script
	if((currentState==HOST_STATE_BUILDING_ONBOARD))
	{
		if(!utility::isPlaying()){
			currentState = HOST_STATE_READY;
		}
	}
}

/** Identify a command packet, and process it.  If the packet is a command
 * packet, return true, indicating that the packet has been queued and no
 * other processing needs to be done. Otherwise, processing of this packet
 * should drop through to the next processing level.
 */
bool processCommandPacket(const InPacket& from_host, OutPacket& to_host) {
	if (from_host.getLength() >= 1) {
		uint8_t command = from_host.read8(0);
		if ((command & 0x80) != 0) {
			// If we're capturing a file to an SD card, we send it to the sdcard module
			// for processing.
			if (sdcard::isCapturing()) {
				sdcard::capturePacket(from_host);
				to_host.append8(RC_OK);
				return true;
			}
			if(sdcard::isPlaying() || utility::isPlaying()){
				// ignore action commands if SD card build is playing
				// or if ONBOARD script is playing
				to_host.append8(RC_OK);
				return true;
			}
			// Queue command, if there's room.
			// Turn off interrupts while querying or manipulating the queue!
			ATOMIC_BLOCK(ATOMIC_FORCEON) {
				const uint8_t command_length = from_host.getLength();
				if (command::getRemainingCapacity() >= command_length) {
					// Append command to buffer
					for (int i = 0; i < command_length; i++) {
						command::push(from_host.read8(i));
					}
					to_host.append8(RC_OK);
				} else {
					to_host.append8(RC_BUFFER_OVERFLOW);
				}
			}
			return true;
		}
	}
	return false;
}

    // alert the host that the bot has had a heat failure
void heatShutdown(){
	currentState == HOST_STATE_HEAT_SHUTDOWN;
}


// Received driver version info, and request for fw version info.
// puts fw version into a reply packet, and send it back
inline void handleVersion(const InPacket& from_host, OutPacket& to_host) {

    // Case to give an error on Replicator G versions older than 0025. See footnote 1
    if(from_host.read16(1)  <=  25   ) {
        to_host.append8(RC_OK);
        to_host.append16(0x0000);
    }
    else  {
        to_host.append8(RC_OK);
        to_host.append16(firmware_version);
    }

}

    // return build name
inline void handleGetBuildName(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	for (uint8_t idx = 0; idx < MAX_FILE_LEN; idx++) {
	  to_host.append8(buildName[idx]);
	  if (buildName[idx] == '\0') { break; }
	}
}

inline void handleGetBufferSize(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	to_host.append32(command::getRemainingCapacity());
}

inline void handleGetPosition(const InPacket& from_host, OutPacket& to_host) {
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		const Point p = steppers::getPosition();
		to_host.append8(RC_OK);
		to_host.append32(p[0]);
		to_host.append32(p[1]);
		to_host.append32(p[2]);
		// From spec:
		// endstop status bits: (7-0) : | N/A | N/A | z max | z min | y max | y min | x max | x min |
		Motherboard& board = Motherboard::getBoard();
		uint8_t endstop_status = 0;
		for (int i = 3; i > 0; i--) {
			StepperInterface& si = board.getStepperInterface(i-1);
			endstop_status <<= 2;
			endstop_status |= (si.isAtMaximum()?2:0) | (si.isAtMinimum()?1:0);
		}
		to_host.append8(endstop_status);
	}
}

inline void handleGetPositionExt(const InPacket& from_host, OutPacket& to_host) {
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		const Point p = steppers::getPosition();
		to_host.append8(RC_OK);
		to_host.append32(p[0]);
		to_host.append32(p[1]);
		to_host.append32(p[2]);
#if STEPPER_COUNT > 3
		to_host.append32(p[3]);
		to_host.append32(p[4]);
#else
		to_host.append32(0);
		to_host.append32(0);
#endif
		// From spec:
		// endstop status bits: (15-0) : | b max | b min | a max | a min | z max | z min | y max | y min | x max | x min |
		Motherboard& board = Motherboard::getBoard();
		uint8_t endstop_status = 0;
		for (int i = STEPPER_COUNT; i > 0; i--) {
			StepperInterface& si = board.getStepperInterface(i-1);
			endstop_status <<= 2;
			endstop_status |= (si.isAtMaximum()?2:0) | (si.isAtMinimum()?1:0);
		}
		to_host.append16(endstop_status);
	}
}

    // capture to SD
inline void handleCaptureToFile(const InPacket& from_host, OutPacket& to_host) {
	char *p = (char*)from_host.getData() + 1;
	to_host.append8(RC_OK);
	to_host.append8(sdcard::startCapture(p));
}
    // stop capture to SD
inline void handleEndCapture(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	to_host.append32(sdcard::finishCapture());
}

    // playback from SD
inline void handlePlayback(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	for (int idx = 1; idx < from_host.getLength(); idx++) {
		buildName[idx-1] = from_host.read8(idx);
	}
	buildName[MAX_FILE_LEN-1] = '\0';

	uint8_t response = startBuildFromSD();
	to_host.append8(response);
}

    // retrive SD file names
inline void handleNextFilename(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	uint8_t resetFlag = from_host.read8(1);
	if (resetFlag != 0) {
		sdcard::SdErrorCode e = sdcard::directoryReset();
		if (e != sdcard::SD_SUCCESS) {
			to_host.append8(e);
			to_host.append8(0);
			return;
		}
	}
	int MAX_FILE_LEN = MAX_PACKET_PAYLOAD-1;
	char fnbuf[MAX_FILE_LEN];
	sdcard::SdErrorCode e;
	// Ignore dot-files
	do {
		e = sdcard::directoryNextEntry(fnbuf,MAX_FILE_LEN);
		if (fnbuf[0] == '\0') break;
	} while (e == sdcard::SD_SUCCESS && fnbuf[0] == '.');
	to_host.append8(e);
	uint8_t idx;
	for (idx = 0; (idx < MAX_FILE_LEN) && (fnbuf[idx] != 0); idx++) {
		to_host.append8(fnbuf[idx]);
	}
	to_host.append8(0);
}

    // pause command response
inline void handlePause(const InPacket& from_host, OutPacket& to_host) {
	command::pause(!command::isPaused());
	to_host.append8(RC_OK);
}

    // check if steppers are still executing a command
inline void handleIsFinished(const InPacket& from_host, OutPacket& to_host) {
	to_host.append8(RC_OK);
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		bool done = !steppers::isRunning() && command::isEmpty();
		to_host.append8(done?1:0);
	}
}
    // read value from eeprom
inline void handleReadEeprom(const InPacket& from_host, OutPacket& to_host) {
    
    uint16_t offset = from_host.read16(1);
    uint8_t length = from_host.read8(3);
    uint8_t data[length];
    eeprom_read_block(data, (const void*) offset, length);
    to_host.append8(RC_OK);
    for (int i = 0; i < length; i++) {
        to_host.append8(data[i]);
    }
}

/**
 * writes a chunk of data from a input packet to eeprom
 */
inline void handleWriteEeprom(const InPacket& from_host, OutPacket& to_host) {
    uint16_t offset = from_host.read16(1);
    uint8_t length = from_host.read8(3);
    uint8_t data[length];
    eeprom_read_block(data, (const void*) offset, length);
    for (int i = 0; i < length; i++) {
        data[i] = from_host.read8(i + 4);
    }
    eeprom_write_block(data, (void*) offset, length);
    to_host.append8(RC_OK);
    to_host.append8(length);
}

enum { // bit assignments
	ES_STEPPERS = 0, // stop steppers
	ES_COMMANDS = 1  // clean queue
};

    // stop steppers and command execution
inline void handleExtendedStop(const InPacket& from_host, OutPacket& to_host) {
	uint8_t flags = from_host.read8(1);
	if (flags & _BV(ES_STEPPERS)) {
		planner::abort();
	}
	if (flags & _BV(ES_COMMANDS)) {
		command::reset();
	}

	to_host.append8(RC_OK);
	to_host.append8(0);
}

    //set build name and build state
void handleBuildStartNotification(CircularBuffer& buf) {
	
	uint8_t idx = 0;
	char newName[MAX_FILE_LEN];
	switch (currentState){
		case HOST_STATE_BUILDING_FROM_SD:
			do {
				newName[idx++] = buf.pop();		
			} while (newName[idx-1] != '\0');
			if(strcmp(newName, "RepG Build"))
				strcpy(buildName, newName);
			break;
		case HOST_STATE_READY:
			currentState = HOST_STATE_BUILDING;
		case HOST_STATE_BUILDING_ONBOARD:
		case HOST_STATE_BUILDING:
			do {
				buildName[idx++] = buf.pop();		
			} while (buildName[idx-1] != '\0');
			break;
	}
}

    // set build state to ready
void handleBuildStopNotification(uint8_t stopFlags) {
	uint8_t flags = stopFlags;

	currentState = HOST_STATE_READY;
}
    // we are not using tool communication.  this is a  legacy function
inline void handleGetCommunicationStats(const InPacket& from_host, OutPacket& to_host) {
        to_host.append8(RC_OK);
        to_host.append32(0);
        to_host.append32(0);//tool::getSentPacketCount());
        to_host.append32(0);//tool::getPacketFailureCount());
        to_host.append32(0);//tool::getRetryCount());
        to_host.append32(0);//tool::getNoiseByteCount());
}

    // query packets (non action, not queued)
bool processQueryPacket(const InPacket& from_host, OutPacket& to_host) {
	if (from_host.getLength() >= 1) {
		uint8_t command = from_host.read8(0);
		if ((command & 0x80) == 0) {
			// Is query command.
			switch (command) {
			case HOST_CMD_VERSION:
				handleVersion(from_host,to_host);
				return true;
			case HOST_CMD_GET_BUILD_NAME:
				handleGetBuildName(from_host,to_host);
				return true;
			case HOST_CMD_INIT:
				// There's really nothing we want to do here; we don't want to
				// interrupt a running build, for example.
				to_host.append8(RC_OK);
				return true;
			case HOST_CMD_CLEAR_BUFFER: // equivalent at current time
			case HOST_CMD_ABORT: // equivalent at current time
			case HOST_CMD_RESET:
				if (currentState == HOST_STATE_BUILDING
						|| currentState == HOST_STATE_BUILDING_FROM_SD
						|| currentState == HOST_STATE_BUILDING_ONBOARD) {
					Motherboard::getBoard().indicateError(ERR_RESET_DURING_BUILD);
				}

				do_host_reset = true; // indicate reset after response has been sent
				to_host.append8(RC_OK);
				return true;
			case HOST_CMD_GET_BUFFER_SIZE:
				handleGetBufferSize(from_host,to_host);
				return true;
			case HOST_CMD_GET_POSITION:
				handleGetPosition(from_host,to_host);
				return true;
			case HOST_CMD_GET_POSITION_EXT:
				handleGetPositionExt(from_host,to_host);
				return true;
			case HOST_CMD_CAPTURE_TO_FILE:
				handleCaptureToFile(from_host,to_host);
				return true;
			case HOST_CMD_END_CAPTURE:
				handleEndCapture(from_host,to_host);
				return true;
			case HOST_CMD_PLAYBACK_CAPTURE:
				handlePlayback(from_host,to_host);
				return true;
			case HOST_CMD_NEXT_FILENAME:
				handleNextFilename(from_host,to_host);
				return true;
			case HOST_CMD_GET_RANGE:
			case HOST_CMD_SET_RANGE:
				break; // not yet implemented
			case HOST_CMD_PAUSE:
				handlePause(from_host,to_host);
				return true;
			case HOST_CMD_TOOL_QUERY:
				processExtruderQueryPacket(from_host,to_host);
				return true;
			case HOST_CMD_IS_FINISHED:
				handleIsFinished(from_host,to_host);
				return true;
			case HOST_CMD_READ_EEPROM:
				handleReadEeprom(from_host,to_host);
				return true;
			case HOST_CMD_WRITE_EEPROM:
				handleWriteEeprom(from_host,to_host);
				return true;
			case HOST_CMD_EXTENDED_STOP:
				handleExtendedStop(from_host,to_host);
				return true;
			case HOST_CMD_GET_COMMUNICATION_STATS:
				handleGetCommunicationStats(from_host,to_host);
				return true;
			}
		}
	}
	return false;
}

char* getMachineName() {
	// If the machine name hasn't been loaded, load it
	if (machineName[0] == 0) {
		for(uint8_t i = 0; i < eeprom_info::MAX_MACHINE_NAME_LEN; i++) {
			machineName[i] = eeprom::getEeprom8(eeprom_offsets::MACHINE_NAME+i, 0);
		}
	}

	// If EEPROM is zero, load in a default. The 0 is there on purpose
	// since this fallback should only happen on EEPROM total failure
	static PROGMEM prog_uchar defaultMachineName[] =  "The Replicat0r";

	if (machineName[0] == 0) {
		for(uint8_t i = 0; i < 14; i++) {
			machineName[i] = pgm_read_byte_near(defaultMachineName+i);
		}
	}

	return machineName;
}

char* getBuildName() {
	return buildName;
}

HostState getHostState() {
	return currentState;
}

sdcard::SdErrorCode startBuildFromSD() {
	sdcard::SdErrorCode e;

	// Attempt to start build
	e = sdcard::startPlayback(buildName);
	if (e != sdcard::SD_SUCCESS) {
		// TODO: report error
		return e;
	}

	currentState = HOST_STATE_BUILDING_FROM_SD;

	return e;
}
    // start build from utility script
void startOnboardBuild(uint8_t  build){
	
	if(utility::startPlayback(build)){
		currentState = HOST_STATE_BUILDING_ONBOARD;
	}
	command::reset();
	planner::abort();
}

// Stop the current build, if any
void stopBuild() {
    // if building from repG, try to send a cancel msg to repG before reseting 
	if(currentState == HOST_STATE_BUILDING)
	{	
		currentState = HOST_STATE_CANCEL_BUILD;
		cancel_timeout.start(1000000); //look for commands from repG for one second before resetting
	}
	do_host_reset = true; // indicate reset after response has been sent
}

    // legacy tool / motherboard breakout of query commands
bool processExtruderQueryPacket(const InPacket& from_host, OutPacket& to_host) {
	Motherboard& board = Motherboard::getBoard();
	if (from_host.getLength() >= 1) {
		
		
        uint8_t	id = from_host.read8(1);
		uint8_t command = from_host.read8(2);
		// All commands are query commands.	
		switch (command) {
		case SLAVE_CMD_VERSION:
			to_host.append8(RC_OK);
			to_host.append16(firmware_version);
			return true;
		case SLAVE_CMD_GET_BUILD_NAME:
			to_host.append8(RC_OK);
			{
			  for (uint8_t idx = 0; idx < 31; idx++) {
			    to_host.append8(build_name[idx]);
			    if (build_name[idx] == '\0') { break; }
			  }
			}
			return true;
		case SLAVE_CMD_INIT:
			do_host_reset = true;
			to_host.append8(RC_OK);
			return true;
		case SLAVE_CMD_GET_TEMP:
			to_host.append8(RC_OK);
			to_host.append16(board.getExtruderBoard(id).getExtruderHeater().get_current_temperature());
			return true;
		case SLAVE_CMD_SET_TEMP:		
			board.getExtruderBoard(id).getExtruderHeater().set_target_temperature(from_host.read16(2));
			to_host.append8(RC_OK);
		    return true;
		case SLAVE_CMD_READ_FROM_EEPROM:
			handleReadEeprom(from_host, to_host);
			return true;
		case SLAVE_CMD_WRITE_TO_EEPROM:
			handleWriteEeprom(from_host, to_host);
			return true;
		// can be removed in process via host query works OK
 		case SLAVE_CMD_PAUSE_UNPAUSE:
			handlePause(from_host, to_host);
			return true;
		case SLAVE_CMD_TOGGLE_FAN:
			board.getExtruderBoard(id).setFan((from_host.read8(2) & 0x01) != 0);
			to_host.append8(RC_OK);
			return true;
		case SLAVE_CMD_TOGGLE_VALVE:
			board.setValve((from_host.read8(3) & 0x01) != 0);
			return true;
		case SLAVE_CMD_IS_TOOL_READY:
			to_host.append8(RC_OK);
			to_host.append8(board.getExtruderBoard(id).getExtruderHeater().has_reached_target_temperature()?1:0);
			return true;
		case SLAVE_CMD_GET_PLATFORM_TEMP:
			to_host.append8(RC_OK);
			to_host.append16(board.getPlatformHeater().get_current_temperature());
			return true;
		case SLAVE_CMD_GET_SP:
			to_host.append8(RC_OK);
			to_host.append16(board.getExtruderBoard(id).getExtruderHeater().get_set_temperature());
			return true;
		case SLAVE_CMD_GET_PLATFORM_SP:
			to_host.append8(RC_OK);
			to_host.append16(board.getPlatformHeater().get_set_temperature());
			return true;
		case SLAVE_CMD_IS_PLATFORM_READY:
			to_host.append8(RC_OK);
			to_host.append8(board.getPlatformHeater().has_reached_target_temperature()?1:0);
			return true;
		case SLAVE_CMD_GET_TOOL_STATUS:
			to_host.append8(RC_OK);
			to_host.append8( (board.getExtruderBoard(id).getExtruderHeater().has_failed()?128:0)
							| (board.getPlatformHeater().has_failed()?64:0)
							| (board.getExtruderBoard(id).getExtruderHeater().has_reached_target_temperature()?1:0));
			return true;
		case SLAVE_CMD_GET_PID_STATE:
			to_host.append8(RC_OK);
			to_host.append16(board.getExtruderBoard(id).getExtruderHeater().getPIDErrorTerm());
			to_host.append16(board.getExtruderBoard(id).getExtruderHeater().getPIDDeltaTerm());
			to_host.append16(board.getExtruderBoard(id).getExtruderHeater().getPIDLastOutput());
			to_host.append16(board.getPlatformHeater().getPIDErrorTerm());
			to_host.append16(board.getPlatformHeater().getPIDDeltaTerm());
			to_host.append16(board.getPlatformHeater().getPIDLastOutput());
			return true;
		}
	}
	return false;
}

}
/* footnote 1: due to a protocol change, replicatiorG 0026 and newer can ONLY work with
 * firmware 3.00 and newer. Because replicatorG handles version mismatches poorly,
 * if our firmware is 3.0 or newer, *AND* the connecting replicatorG is 25 or older, we
 * lie, and reply with firmware 0.00 to case ReplicatorG to display a 'null version' error
 * so users will know to upgrade.
 */
