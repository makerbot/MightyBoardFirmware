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

#ifndef UTILITY_SCRIPTS
#define UTILITY_SCRIPTS

#include "Types.hh"
#include "Menu_locales.hh"

POST_LEVEL_TEST
POST_LEVEL_HBP_START
POST_LEVEL_NOHBP_START
POST_LEVEL_HBP_END
POST_LEVEL_NOHBP_END


#define POST_LEVEL_PLAYLIST_LEN 3

static uint8_t* PostLevelHBPPlaylist[] = {PostLevelHBPStart, PostLevelTestPrint, PostLevelHBPEnd};

static uint8_t* PostLevelNoHBPPlaylist[] = {PostLevelNoHBPStart, PostLevelTestPrint, PostLevelNoHBPEnd};

static uint16_t PostLevelHBPPlaylistLengths[] = {POST_LEVEL_HBP_START_LEN, POST_LEVEL_TEST_LEN, POST_LEVEL_HBP_END_LEN};

static uint16_t PostLevelNoHBPPlaylistLengths[] = {POST_LEVEL_NOHBP_START_LEN, POST_LEVEL_TEST_LEN, POST_LEVEL_NOHBP_END_LEN};

namespace utility {
	
	enum ScriptName{
		HOME_AXES = 0,
	  LEVEL_PLATE_STARTUP = 1,
	  TOOLHEAD_CALIBRATE = 2,
	  LEVEL_PLATE_SECOND = 3,
    POST_LEVEL = 4
  };
	
 /// returns true if script is running
 bool isPlaying();
 
 /// returns true if more bytes are available in the script
 bool playbackHasNext();
 
 /// gets next byte in script
 uint8_t playbackNext();
 
 /// begin buffer playback
 bool startPlayback(uint8_t build);
 
 /// updates state to finished playback
 void finishPlayback();
 
 /// reset pointers
 void reset();

 /// change the build index of the script
 void getSecondLevelOffset(void);

 /// return true if we should show the monitor screen during the utility script
 bool showMonitor();

 //returns true if there are more parts othe the Post Leveling script to run
 //if there is more to be played it indexs to the next part of the script
 bool continuePostLevelPlaylist();

};

#endif
