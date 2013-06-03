/*
 * Copyright 2012 by Alison Leonard <alison@makerbot.com>
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
 
 #include "Interface.hh"
 #include <util/delay.h>
 
 #include "UtilityScripts.hh"
 #include <avr/pgmspace.h>
 #include "EepromMap.hh"

 
/// the gcode and s3g files for these scripts are located in firmware/s3g_scripts
/// the script loadDataFile.py converts s3g files to byte arrays to store in PROGMEM
/// the script lengths are given by the output of the loadDataFile.py script
 static uint16_t Lengths[4]  PROGMEM = { HOME_AXES_SCRIPT_LEN, /// Home Axes
                                         LEVEL_PLATE_LEN_SINGLE,
                                         LEVEL_PLATE_LEN_DUAL,
                                         4351}; /// nozzle (toolhead) calibrate
                            
HOME_AXES_SCRIPT
LEVEL_PLATE_SINGLE
LEVEL_PLATE_DUAL
NOZZLE_CALIBRATE

 namespace utility {
	 
	 volatile bool is_playing;
	 int build_index = 0;
	 int build_length = 0;
	 uint8_t * buildFile;
   bool show_monitor;
	  
 /// returns true if script is running
 bool isPlaying(){
	 
	 return is_playing;		 
 }
 void reset(){
	 uint16_t build_index = 0;
	 uint16_t build_length = 0;
	 is_playing = false;
   show_monitor = true;
 
 }
 
 /// returns true if more bytes are available in the script
 bool playbackHasNext(){
	return (build_index < build_length);
 }
 
 /// gets next byte in script
 uint8_t playbackNext(){
	 
	 uint8_t byte;
	 
	 if(build_index < build_length)
	 {
		 byte = pgm_read_byte(buildFile + build_index++);
		return byte;
	}
	else 
		return 0;
 }

 bool showMonitor(){
  return show_monitor;
 }
 
 /// begin buffer playback
 bool startPlayback(uint8_t build){
	 
   is_playing = true;
   build_index = 0;
   show_monitor = false;

     // get build file
	switch (build){
    case HOME_AXES:
			buildFile = HomeAxes;		
			break;
		case LEVEL_PLATE_STARTUP:
			if(eeprom::isSingleTool()){
        buildFile = LevelPlateSingle;
        build = LEVEL_PLATE_STARTUP;
			} else{
        buildFile = LevelPlateDual; 
        build = LEVEL_PLATE_STARTUP + 1;
			}
			break;
		case TOOLHEAD_CALIBRATE:
      show_monitor = true;
      buildFile = NozzleCalibrate;
      build = TOOLHEAD_CALIBRATE + 1;
			break;
		default:
      is_playing = false;
			return false;
	}
	
    // get build length
	 build_length = pgm_read_word(Lengths + build);
	 
	 return is_playing;
 }
     
 /// updates state to finished playback
 void finishPlayback(){
	is_playing = false;;
	show_monitor = true;
 }
};

