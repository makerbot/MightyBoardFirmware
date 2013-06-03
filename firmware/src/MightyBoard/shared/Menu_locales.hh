#ifndef __MENU__LOCALES__
#define __MENU__LOCALES__

#include <avr/pgmspace.h>
#include <string.h>

#define FRENCH 1

#ifdef PROGMEM 
# undef PROGMEM 
# define PROGMEM __attribute__((section(".progmem.data"))) 
#endif

#pragma GCC diagnostic ignored "-Wunused-variable"

static PROGMEM unsigned char ON_MSG[] =					"ON ";
static PROGMEM unsigned char OFF_MSG[] =				"OFF";
static PROGMEM unsigned char NA2_MSG[] =				"NA ";

static PROGMEM unsigned char ON_CELCIUS_MSG[] =				"/   C";
static PROGMEM unsigned char CELCIUS_MSG[] =				"C    ";
static PROGMEM unsigned char ARROW_MSG[] =				"-->";
static PROGMEM unsigned char NO_ARROW_MSG[] =				"   ";
static PROGMEM unsigned char BLANK_CHAR_MSG[] =				" ";

static PROGMEM unsigned char CLEAR_MSG[] =				"                    ";
static PROGMEM unsigned char BLANKLINE_MSG[] =				"                ";

#ifdef LOCALE_FR
# include "Menu.FR.hh"
#else // Use US ENGLISH as default

#ifdef MODEL_REPLICATOR
static PROGMEM unsigned char SPLASH1_SINGLE_MSG[] = 			"  The Replicator    ";
static PROGMEM unsigned char SPLASH1_DUAL_MSG[] =			"  The Replicator    ";
static PROGMEM unsigned char SPLASH2_MSG[] =				"    ----------      ";
#elif MODEL_REPLICATOR2
static PROGMEM unsigned char SPLASH1_SINGLE_MSG[] =			" The Replicator 2   ";
static PROGMEM unsigned char SPLASH1_DUAL_MSG[] =			" The Replicator 2X  ";
static PROGMEM unsigned char SPLASH2_MSG[] =				"  --------------    ";
#else
static PROGMEM unsigned char SPLASH1_MSG[] =				"     Makerbot       ";
static PROGMEM unsigned char SPLASH2_MSG[] =				"    ----------      ";
#endif

static PROGMEM unsigned char SPLASH3_MSG[] =				"                    ";
static PROGMEM unsigned char SPLASH4_MSG[] =				"Firmware Version 7. ";
static PROGMEM unsigned char SPLASH5_MSG[] =				"Internal Release    ";

static PROGMEM unsigned char SPLASH1A_MSG[] =				"    FAIL!           ";
static PROGMEM unsigned char SPLASH2A_MSG[] =				"    SUCCESS!        ";
static PROGMEM unsigned char SPLASH3A_MSG[] =				"connected correctly ";
static PROGMEM unsigned char SPLASH4A_MSG[] =				"Heaters are not     ";
static PROGMEM unsigned char SPLASH5A_MSG[] =				"                    ";	

static PROGMEM unsigned char GO_MSG[] =					"Start Preheat!";
static PROGMEM unsigned char STOP_MSG[] =				"Cool!";
static PROGMEM unsigned char RIGHT_TOOL_MSG[] =				"Right Tool";
static PROGMEM unsigned char LEFT_TOOL_MSG[] =				"Left Tool";
static PROGMEM unsigned char PLATFORM_MSG[] =				"Platform";
static PROGMEM unsigned char TOOL_MSG[] =				"Extruder";

#ifdef MODEL_REPLICATOR2
static PROGMEM unsigned char START_MSG[] =				"Welcome! I'm        " \
									"The Replicator 2.   " \
									"Press the red M to  " \
									"get started!        ";

static PROGMEM unsigned char START_DUAL_MSG[] =				"Welcome! I'm        " \
									"The Replicator 2X.  " \
									"Press the red M to  " \
									"get started!        ";
#else
static PROGMEM unsigned char START_MSG[] =				"Welcome!            " \
									"I'm The Replicator. " \
									"Press the red M to  " \
									"get started!        ";
static PROGMEM unsigned char START_DUAL_MSG[] =				"Welcome!            " \
									"I'm The Replicator. " \
									"Press the red M to  " \
									"get started!        ";
#endif
static PROGMEM unsigned char BUTTONS1_MSG[] =				"A blinking 'M' means" \
									"I'm waiting and will" \
									"continue when you   " \
									"press the button... ";
static PROGMEM unsigned char BUTTONS2_MSG[] =				"A solid 'M' means   " \
									"I'm working and will" \
									"update my status    " \
									"when I'm finished...";
static PROGMEM unsigned char EXPLAIN_MSG[] =				"Our next steps will " \
									"get me set up!      " \
									"First, we'll restore" \
									"my build platform...";                                  
static PROGMEM unsigned char LEVEL_MSG[] =				"so it's nice and    " \
									"level. It's probably" \
									"a bit off from      " \
									"shipping...         ";
static PROGMEM unsigned char BETTER_MSG[] =				"Aaah, that feels    " \
									"much better.        " \
									"Let's go on and load" \
									"some filament!      ";
static PROGMEM unsigned char TRYAGAIN_MSG[] =				"We'll try again!    " \
									"                    " \
									"                    " \
									"                    ";
static PROGMEM unsigned char GO_ON_MSG[]   =				"We'll keep going    " \
									"and load some       " \
									"filament,For help go" \
									"to makerbot.com/help";     
static PROGMEM unsigned char SD_MENU_MSG[] =				"Awesome!            " \
									"We'll go to the SD  " \
									"card menu and you   " \
									"can select a model! ";
static PROGMEM unsigned char FAIL_MSG[] =				"We'll go to the main" \
									"menu. If you need   " \
									"help go to:         " \
									"makerbot.com/help   ";
static PROGMEM unsigned char START_TEST_MSG[]=				"I'm going to make   " \
									"a series of lines so" \
									"we can find my      " \
									"nozzle alignment.   "; // XXX old name: start[]
static PROGMEM unsigned char EXPLAIN1_MSG[] =				"Look for the best   " \
									"matched line in each" \
									"axis set. Lines are " \
									"numbered 1-13 and...";
static PROGMEM unsigned char EXPLAIN2_MSG[] =				"line one is extra   " \
									"long. The Y axis set" \
									"is left on the plate" \
									"and X axis is right.";
static PROGMEM unsigned char END_MSG  [] =				"Great!  I've saved  " \
									"these settings and  " \
									"I'll use them to    " \
									"make nice models!   ";

static PROGMEM unsigned char SELECT_MSG[] =				"Select best lines.";
static PROGMEM unsigned char DONE_MSG[]   =				"Done!";
static PROGMEM unsigned char NO_MSG[]   =				"No    ";
static PROGMEM unsigned char YES_MSG[]  =				"Yes   ";

static PROGMEM unsigned char XAXIS_MSG[] =				"X Axis Line";
static PROGMEM unsigned char YAXIS_MSG[] =				"Y Axis Line";

static PROGMEM unsigned char HEATER_ERROR_MSG[]=			"My extruders are    " \
									"not heating up.     " \
									"Check my            " \
									"connections!        ";
#ifdef MODEL_REPLICATOR2
static PROGMEM unsigned char EXPLAIN_ONE_MSG[] =			"I'm heating up my   " \
									"extruder so we can  " \
									"load the filament.  " \
									"Be careful, the...  ";
static PROGMEM unsigned char EXPLAIN_TWO_MSG[] =			"nozzle will get hot!" \
									"While I'm heating,  " \
									"remove the filament " \
									"tube from the...    ";
static PROGMEM unsigned char EXPLAIN_ONE_S_MSG[]=			"I'm heating up my   " \
									"extruder so we can  " \
									"load the filament.  " \
									"Be careful, the...  ";
static PROGMEM unsigned char EXPLAIN_TWO_S_MSG[]=			"nozzle will get hot!" \
									"While I'm heating,  " \
									"remove the filament " \
									"tube from the...    ";
static PROGMEM unsigned char EXPLAIN_THRE_MSG[]=			"extruder block. Feed" \
									"filament from the   " \
									"spool through the   " \
									"tube until it...    ";
static PROGMEM unsigned char EXPLAIN_FOUR_MSG[]=			"pops out in front.  " \
									"When the filament is" \
									"ready, press 'M' to " \
									"continue.           ";
#else
static PROGMEM unsigned char EXPLAIN_ONE_MSG[] =			"Press down on the   " \
									"grey rings at top of" \
									"the extruders and   " \
									"pull the black...   ";
static PROGMEM unsigned char EXPLAIN_TWO_MSG[] =			"guide tubes out. Now" \
									"feed filament from  " \
									"the back through the" \
									"tubes until it...   ";
static PROGMEM unsigned char EXPLAIN_ONE_S_MSG[]=			"Press down on the   " \
									"grey ring at top of " \
									"the extruder and    " \
									"pull the black...   ";
static PROGMEM unsigned char EXPLAIN_TWO_S_MSG[]=			"guide tube out.  Now" \
									"feed filament from  " \
									"the back through the" \
									"tube until it...    ";
static PROGMEM unsigned char EXPLAIN_THRE_MSG[]=			"pops out in front.  " \
									"I'm heating up my   " \
									"extruder so we can  " \
									"load the filament...";
static PROGMEM unsigned char EXPLAIN_FOUR_MSG[]=			"This might take a   " \
									"few minutes.        " \
									"And watch out, the  " \
									"nozzle will get HOT!";
#endif

static PROGMEM unsigned char HEATING_BAR_MSG[] =			"Please wait while I " \
									"heat my extruder!   " \
									"                    " \
									"                    ";
static PROGMEM unsigned char HEATING_PROG_MSG[]=			"Heating Progress:   " \
									"                    " \
									"                    " \
									"                    ";
static PROGMEM unsigned char READY_SS_MSG[]    =			"OK I'm ready!       " \
									"Push the filament   " \
									"through...          " \
									"                    ";
static PROGMEM unsigned char READY_RIGHT_MSG[] =			"OK I'm ready!       " \
									"First we'll load the" \
									"right extruder.     " \
									"Push filament in... ";
static PROGMEM unsigned char READY_LEFT_MSG[]  =			"Great! Now we'll    " \
									"load the left       " \
									"extruder. Push      " \
									"filament through... ";
static PROGMEM unsigned char READY_SINGLE_MSG[]=			"I'm ready! Pull the " \
									"guide tube off and  " \
									"push the filament   " \
									"through...          ";
#ifdef MODEL_REPLICATOR
static PROGMEM unsigned char READY_REV_MSG[]   =			"I'm ready! Pull the " \
									"guide tube off and  " \
									"pull the filament   " \
									"gently...           ";
static PROGMEM unsigned char READY_REV_DUAL_R_MSG[]   =			"I'm ready! Detach   " \
									"the guide tube, open" \
									"the lever arm and   " \
									"pull filament free. ";
static PROGMEM unsigned char READY_REV_DUAL_L_MSG[]   =			"I'm ready! Detach   " \
									"the guide tube, open" \
									"the lever arm and   " \
									"pull filament free. ";
#else
static PROGMEM unsigned char READY_REV_MSG[]   =			"I'm ready! Pull the " \
									"guide tube off and  " \
									"pull the filament   " \
									"gently...           ";
static PROGMEM unsigned char READY_REV_DUAL_R_MSG[]   =			"I'm ready! Detach   " \
									"the guide tube and  " \
									"move the lever to   " \
									"the right.  Pull... ";
static PROGMEM unsigned char READY_REV_DUAL_L_MSG[]   =			"I'm ready! Detach   " \
									"the guide tube and  " \
									"move the lever to   " \
									"the left.  Pull...  ";
#endif
static PROGMEM unsigned char TUG_MSG[]         =			"until you feel the  " \
									"motor tug it in.    " \
									"Push for a few more " \
									"seconds, then wait. ";
static PROGMEM unsigned char STOP_MSG_MSG[]    =			"When filament is    " \
									"being extruded from " \
									"the nozzle, Press M " \
									"to stop extruding.  ";  // XXX old name: stop[]
static PROGMEM unsigned char STOP_EXIT_MSG[]   =			"When filament is    " \
									"being extruded from " \
									"the nozzle,         " \
									"Press 'M' to exit.  "; 
#ifdef MODEL_REPLICATOR2
static PROGMEM unsigned char STOP_REVERSE_MSG[]=			"When my filament is " \
									"released,           " \
									"Press 'M' to exit.  " \
									"                    ";            
static PROGMEM unsigned char STOP_REV_DUAL_MSG[]=			"filament free and   " \
									"close the lever.    " \
									"Press 'M' to exit.  " \
									"                    ";            
#else
static PROGMEM unsigned char STOP_REVERSE_MSG[]=			"When my filament is " \
									"released,           " \
									"Press 'M' to exit.  " \
									"                    ";            
static PROGMEM unsigned char STOP_REV_DUAL_MSG[]=			"When my filament is " \
									"released,           " \
									"Press 'M' to exit.  " \
									"                    ";            
#endif
static PROGMEM unsigned char PUSH_HARDER_MSG[] =			"OK! I'll keep my    " \
									"motor running. You  " \
									"may need to push    " \
									"harder...           ";  // XXX old name: tryagain[]
static PROGMEM unsigned char KEEP_GOING_MSG[]  =			"We'll keep going.   " \
									"If you're having    " \
									"trouble, check out  " \
									"makerbot.com/help   ";  // XXX old name: go_on[]
static PROGMEM unsigned char FINISH_MSG[]      =			"Great!  I'll stop   " \
									"running my extruder." \
									"Press M to continue." \
									"                    ";  
static PROGMEM unsigned char GO_ON_LEFT_MSG[]  =			"We'll keep going.   " \
									"Lets try the left   " \
									"extruder. Push      " \
									"filament down...    ";
static PROGMEM unsigned char TIMEOUT_MSG[]		=		"My motor timed out  " \
									"after 5 minutes.    " \
									"Press M to exit.    " \
									"                    ";

static PROGMEM unsigned char READY1_MSG[] =				"How'd it go? Ready  ";
static PROGMEM unsigned char READY2_MSG[] =				"to make something?  ";
static PROGMEM unsigned char NOZZLE_MSG_MSG[] =				"Does my nozzle ";        // XXX old name: ready1[]
static PROGMEM unsigned char HEIGHT_CHK_MSG[] =				"height check out? ";     // XXX old name: ready2[]
static PROGMEM unsigned char HEIGHT_GOOD_MSG[]=				"My height is good!  ";   // XXX old name: yes[]
static PROGMEM unsigned char TRY_AGAIN_MSG[]  =				"Let's try again.";       // XXX old name: no[]

static PROGMEM unsigned char QONE_MSG[] =				"Did plastic extrude ";
static PROGMEM unsigned char QTWO_MSG[] =				"from the nozzle?    ";
static PROGMEM unsigned char LOAD_RIGHT_MSG[] =				"Load right"; 
static PROGMEM unsigned char LOAD_LEFT_MSG[] =				"Load left"; 
static PROGMEM unsigned char LOAD_SINGLE_MSG[] =			"Load"; 
static PROGMEM unsigned char UNLOAD_SINGLE_MSG[]=			"Unload"; 
static PROGMEM unsigned char UNLOAD_RIGHT_MSG[]=			"Unload right"; 
static PROGMEM unsigned char UNLOAD_LEFT_MSG[] =			"Unload left"; 

static PROGMEM unsigned char JOG1_MSG[]  =				"     Jog mode       ";
static PROGMEM unsigned char JOG2X_MSG[] =				"        X+          ";
static PROGMEM unsigned char JOG3X_MSG[] =				"      (Back)   Y->  ";
static PROGMEM unsigned char JOG4X_MSG[] =				"        X-          ";
static PROGMEM unsigned char JOG2Y_MSG[] =				"        Y+          ";
static PROGMEM unsigned char JOG3Y_MSG[] =				"  <-X (Back)  Z->   ";
static PROGMEM unsigned char JOG4Y_MSG[] =				"        Y-          ";
static PROGMEM unsigned char JOG2Z_MSG[] =				"        Z-          ";
static PROGMEM unsigned char JOG3Z_MSG[] =				"  <-Y (Back)        ";
static PROGMEM unsigned char JOG4Z_MSG[] =				"        Z+          ";


static PROGMEM unsigned char DISTANCESHORT_MSG[] =			"SHORT";
static PROGMEM unsigned char DISTANCELONG_MSG[] =			"LONG";
static PROGMEM unsigned char GAMEOVER_MSG[] =				"GAME OVER!";


static PROGMEM unsigned char HEATING_MSG[] =				"Heating:";
static PROGMEM unsigned char HEATING_SPACES_MSG[] =			"Heating:            ";

static PROGMEM unsigned char BUILD_PERCENT_MSG[] =			" --%";
static PROGMEM unsigned char EXTRUDER1_TEMP_MSG[] =			"R Extruder: ---/---C";
static PROGMEM unsigned char EXTRUDER2_TEMP_MSG[] =			"L Extruder: ---/---C";
static PROGMEM unsigned char PLATFORM_TEMP_MSG[]  =			"Platform:   ---/---C";
static PROGMEM unsigned char EXTRUDER_TEMP_MSG[]  =			"Extruder:   ---/---C";


static PROGMEM unsigned char PREHEAT_SET_MSG[] =			" Preheat Settings   ";
static PROGMEM unsigned char RIGHT_SPACES_MSG[] =			"Right Tool          ";    // XXX old name: right[]
static PROGMEM unsigned char LEFT_SPACES_MSG[]   =			"Left Tool           ";   // XXX old name: left[]
static PROGMEM unsigned char PLATFORM_SPACES_MSG[]  =			"Platform        ";    // XXX old name: platform[]
static PROGMEM unsigned char RESET1_MSG[] =				" Reset Settings to  ";       // XXX old name: set1[]
static PROGMEM unsigned char RESET2_MSG[] =				" Default values?";
static PROGMEM unsigned char CANCEL_MSG[] =				"Cancel this build?";
static PROGMEM unsigned char CANCEL_PROCESS_MSG[] =			"Quit this process?";

static PROGMEM unsigned char PAUSE_MSG[] =				"Pause              ";
static PROGMEM unsigned char UNPAUSE_MSG[] =				"UnPause            ";


static PROGMEM unsigned char NOCARD_MSG[] =				"No SD card found";
static PROGMEM unsigned char CARDERROR_MSG[] =				"SD card read error";
static PROGMEM unsigned char CARDFORMAT_MSG[] =				"I can't read this   " \
									"SD card format!     " \
									"Try reformatting    " \
									"the card to FAT16.  ";
static PROGMEM unsigned char STATICFAIL_MSG[] =				"I saw a glitch in my" \
									"SD card. If this is " \
									"the first error, try" \
									"this model again.   ";
static PROGMEM unsigned char CARDSIZE_MSG[]   =				"I can't read SD     " \
									"cards with storage  " \
									"larger than 2GB.    " \
									"                    ";

static PROGMEM unsigned char BUILD_MSG[] =				"Build from SD      ";
static PROGMEM unsigned char PREHEAT_MSG[] =				"Preheat            ";
static PROGMEM unsigned char UTILITIES_MSG[] =				"Utilities          ";
static PROGMEM unsigned char MONITOR_MSG[] =				"Monitor Mode       ";
static PROGMEM unsigned char JOG_MSG[]   =				"Jog Mode           ";
static PROGMEM unsigned char CALIBRATION_MSG[] =			"Calibrate Axes     ";
static PROGMEM unsigned char HOME_AXES_MSG[] =				"Home Axes          ";
static PROGMEM unsigned char FILAMENT_OPTIONS_MSG[] =			"Change Filament    ";
static PROGMEM unsigned char STARTUP_MSG[] =				"Run Startup Script ";
static PROGMEM unsigned char VERSION_MSG[] =				"Version Number     ";
static PROGMEM unsigned char DSTEPS_MSG[] =				"Disable Steppers   ";
static PROGMEM unsigned char ESTEPS_MSG[] =				"Enable Steppers    ";
static PROGMEM unsigned char PLATE_LEVEL_MSG[] =			"Level Build Plate  ";
static PROGMEM unsigned char LED_BLINK_MSG[] =				"Blink LEDs         ";
static PROGMEM unsigned char LED_STOP_MSG[] =				"Stop Blinking!     ";
static PROGMEM unsigned char PREHEAT_SETTINGS_MSG[] =			"Preheat Settings   ";
static PROGMEM unsigned char SETTINGS_MSG[] =				"General Settings   ";
static PROGMEM unsigned char RESET_MSG[] =				"Restore Defaults   ";
static PROGMEM unsigned char NOZZLES_MSG[] =				"Calibrate Nozzles  ";
static PROGMEM unsigned char TOOL_COUNT_MSG[]   =			"Tool Count         ";
static PROGMEM unsigned char SOUND_MSG[] =				"Sound              ";
static PROGMEM unsigned char HEIGHT_EN_MSG[] =				"Pause Active       "; // Label totally not right 
static PROGMEM unsigned char HEIGHT_VALUE_MSG[] =			"Z Position      mm ";
static PROGMEM unsigned char LED_MSG[] =				"LED Color          ";
static PROGMEM unsigned char LED_HEAT_MSG[] =				"Heat LEDs          ";
static PROGMEM unsigned char HEAT_TIMEOUT_MSG[] =			"Heat Hold      m   ";
static PROGMEM unsigned char HELP_SCREENS_MSG[] =			"Help Text          ";
static PROGMEM unsigned char EXIT_MSG[] =				      "<< Exit Menu       ";
static PROGMEM unsigned char ACCELERATE_MSG[] =				"Accelerate         ";
static PROGMEM unsigned char BOT_STATS_MSG[] =				"Bot Statistics     ";
static PROGMEM unsigned char INFO_MSG[] 		=		"Info and Settings  ";


static PROGMEM unsigned char PLATFORM_EXIST_MSG[] =			"Heated Plate";

static PROGMEM unsigned char RED_COLOR_MSG[]    =			"RED   ";
static PROGMEM unsigned char ORANGE_COLOR_MSG[] =			"ORANGE";
static PROGMEM unsigned char PINK_COLOR_MSG[]   =			"PINK  ";
static PROGMEM unsigned char GREEN_COLOR_MSG[]  =			"GREEN ";
static PROGMEM unsigned char BLUE_COLOR_MSG[]   =			"BLUE  ";
static PROGMEM unsigned char PURPLE_COLOR_MSG[] =			"PURPLE";
static PROGMEM unsigned char WHITE_COLOR_MSG[]  =			"WHITE ";
static PROGMEM unsigned char CUSTOM_COLOR_MSG[] =			"CUSTOM";
static PROGMEM unsigned char OFF_COLOR_MSG[] 	 =			"OFF   ";

static PROGMEM unsigned char TOOL_SINGLE_MSG[] =			"SINGLE";
static PROGMEM unsigned char TOOL_DUAL_MSG[] =				"DUAL  ";

static PROGMEM unsigned char RIGHT_MSG[] =				"Right";
static PROGMEM unsigned char LEFT_MSG[] =				"Left";
static PROGMEM unsigned char ERROR_MSG[] =				"error!";
static PROGMEM unsigned char NA_MSG[] =					"  NA    ";
static PROGMEM unsigned char WAITING_MSG[] =				"waiting ";
static PROGMEM unsigned char WAIT_FOR_HOMING_MSG[] =			"Waiting for Homing ";

static PROGMEM unsigned char HEATER_INACTIVITY_MSG[] =			"Heaters shutdown    " \
									"due to inactivity   ";
static PROGMEM unsigned char HEATER_FAIL_SOFTWARE_CUTOFF_MSG[] =	"Heating Failure #1! " \
									"Software Temp Limit " \
									"Reached! Please     " \
									"Shutdown or Restart ";
/*static PROGMEM unsigned char HEATER_FAIL_HARDWARE_CUTOFF_MSG[] =	"Extruder Overheat!  " \
									"Safety Cutoff       " \
									"Triggered! Please   " \
									"Shutdown or Restart ";
*/
static PROGMEM unsigned char HEATER_FAIL_NOT_HEATING_MSG[] =		"Heating Failure #2! " \
									"My extruders are not" \
									"heating properly.   " \
									"Check my connections";

static PROGMEM unsigned char HEATER_FAIL_DROPPING_TEMP_MSG[] =		"Heating Failure #3! " \
									"My extruders are    " \
									"losing temperature. " \
									"Check my connections";

static PROGMEM unsigned char HEATER_FAIL_NOT_PLUGGED_IN_MSG[] =		"Heating Failure #4! " \
									"My temperature reads" \
									"are failing! Please " \
									"Check my connections";

static PROGMEM unsigned char HEATER_FAIL_READ_TEMP_OUT_OF_RANGE_MSG[] =	"Heating Failure #5! " \
									"I'm reading out of  " \
									"range temperatures. " \
									"Check my connections";

static PROGMEM unsigned char TOTAL_TIME_MSG[]       =			"Estimated Build Time" \
									"Lifetime Total:    h";
static PROGMEM unsigned char LAST_TIME_MSG[]        =			"Last Build:     h  m";
static PROGMEM unsigned char BUILD_TIME_MSG[]	     =			"Build Time:     h  m"; 
static PROGMEM unsigned char LINE_NUMBER_MSG[]      =			"Line:               ";
static PROGMEM unsigned char BUILD_FINISHED_MSG []  =			"Build Finished!     " \
									"                    " \
									"Build Time      h  m";
static PROGMEM unsigned char TIME_SPECIFYING_LETTERS[] =		"h  m";
static PROGMEM unsigned char CLEAR_TIME_SPECIFYING_LETTERS[] =		"      ";
static PROGMEM unsigned char CLEAR_TIME_SPECIFYING_LETTERS_1DIGIT_H[] =	"     ";

static PROGMEM unsigned char BACK_TO_MONITOR_MSG[]  =			"Back to Monitor    ";
static PROGMEM unsigned char STATS_MSG[]			 =	"Build Statistics   ";
static PROGMEM unsigned char CHANGE_FILAMENT_HEIGHT_MSG[]	 =	"Z Pause Height     ";
static PROGMEM unsigned char CHANGE_FILAMENT_HEIGHT_HEADING[]	 =	"   Z Pause Height   ";
static PROGMEM unsigned char CANCEL_BUILD_MSG[]     =			"Cancel Build       "; 
static PROGMEM unsigned char CHANGE_FILAMENT_MSG[]  =			"Change Filament    "; 

static PROGMEM unsigned char CANCEL_PLATE_MSG[] =			"I'm Cancelling.     " \
									"Please Wait.        ";

static PROGMEM unsigned char SLEEP_MSG[]  			 =	"Sleep (Cold Pause) ";
static PROGMEM unsigned char RESTART_MSG[]			 =	"Resume Build       ";

static PROGMEM unsigned char CHANGE_FILAMENT_WAIT_MSG[] =		"Changing Filament:  " \
									"I'm completing any  " \
									"queued moves.       "; 
static PROGMEM unsigned char CHANGE_FILAMENT_PREP_MSG[] =		"Changing Filament:  " \
									"I'm going to my wait" \
									"position.           ";

static PROGMEM unsigned char TIMED_OUT_OF_CHANGE_FILAMENT[] =		"My heaters timed out" \
									"I am now in Sleep   " \
									"(Cold Pause).       " \
									"                    ";

static PROGMEM unsigned char SLEEP_WAIT_MSG[] =				"Preparing for sleep:" \
									"I'm completing any  " \
									"queued moves.       "; 
static PROGMEM unsigned char SLEEP_PREP_MSG[] =				"Preparing for sleep:" \
									"I'm cooling my      " \
									"heaters and going to" \
									"my wait position.   ";
static PROGMEM unsigned char RESTARTING_MSG[] =				"Restarting the Build";

static PROGMEM unsigned char ERROR_STREAM_INCOMPATIBLE_REP1[] =		"Warning:Build speeds" \
									"faster than 50mm/s  " \
									"require x3g format  " \
									"for best results.   "; 
static PROGMEM unsigned char ERROR_STREAM_VERSION[] =			"This is not the x3g " \
									"version I work best " \
									"with. For help see: " \
									"makerbot.com/help   ";
static PROGMEM unsigned char ERROR_BOT_TYPE_REP1[] =			"I am a Replicator.  " \
									"This build is for   " \
									"another bot. See:   " \
									"makerbot.com/help   ";
static PROGMEM unsigned char ERROR_BOT_TYPE_REP2[] =			"I am a Replicator 2." \
									"This build is for   " \
									"another bot. See:   " \
									"makerbot.com/help   ";
static PROGMEM unsigned char ERROR_SRAM[] =				"MY SRAM USAGE IS    " \
									"OVER THE 8K LIMIT!  ";
static PROGMEM unsigned char ERROR_SD_CARD_REMOVED[] =			"SD Card Removed    ";
static PROGMEM unsigned char ERROR_PLATFORM_HEATING_TIMEOUT[] =		"I timed out while   " \
									"attempting to heat  " \
									"my platform.        ";
static PROGMEM unsigned char ERROR_HEATING_TIMEOUT[] =			"I timed out while   " \
									"attempting to heat  " \
									"my extruder.        ";
static PROGMEM unsigned char ERROR_SD_CARD_BUILDING[] =			"I'm already building";
static PROGMEM unsigned char ERROR_SD_CARD_GENERIC[] =			" SD card read error";
static PROGMEM unsigned char ERROR_TEMP_RESET_EXTERNALLY[] =		"My temperature was  " \
									"changed externally. " \
									"Reselect filament   " \
									"menu to try again.  ";

static PROGMEM unsigned char ERROR_INVALID_PLATFORM[] =			"INVALID COMMAND:    " \
									"I received a command" \
									"for a heated plate, " \
									"but I don't have one";
static PROGMEM unsigned char ERROR_INVALID_TOOL[] =			"INVALID TOOL:       " \
									"I received a Left   " \
									"Tool command, but I " \
									"only have one Tool. ";
static PROGMEM unsigned char ACTIVE_FAN_MSG[]		 =		"Filament Fan       ";

/// The level Plate Scripts walk users through a procedure to level the build plate
/// the gcode and s3g files for these scripts are located in firmware/s3g_scripts
/// the script loadDataFile.py converts s3g files to byte arrays to store in PROGMEM


#ifdef MODEL_REPLICATOR2
# define LEVEL_PLATE_SINGLE static uint8_t LevelPlateSingle[] PROGMEM = { 149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  132,  3,  125,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  151,  52,  0,  0,  243,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  105,  103,  104,  116,  101,  110,  32,  101,  97,  99,  104,  32,  111,  102,  32,  116,  104,  101,  32,  0,  149,  1,  0,  0,  0,  116,  104,  114,  101,  101,  32,  107,  110,  111,  98,  115,  32,  117,  110,  100,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  98,  117,  105,  108,  100,  32,  112,  108,  97,  116,  102,  111,  114,  109,  32,  32,  0,  149,  7,  0,  0,  0,  97,  98,  111,  117,  116,  32,  102,  111,  117,  114,  32,  116,  117,  114,  110,  115,  46,  0,  149,  0,  0,  0,  0,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  109,  111,  118,  101,  32,  109,  121,  0,  149,  1,  0,  0,  0,  101,  120,  116,  114,  117,  100,  101,  114,  32,  97,  114,  111,  117,  110,  100,  32,  116,  111,  32,  32,  0,  149,  1,  0,  0,  0,  100,  105,  102,  102,  101,  114,  101,  110,  116,  32,  112,  111,  105,  110,  116,  115,  32,  115,  111,  32,  0,  149,  7,  0,  0,  0,  121,  111,  117,  32,  99,  97,  110,  32,  99,  104,  101,  99,  107,  46,  46,  46,  0,  149,  0,  0,  0,  0,  116,  104,  101,  32,  104,  101,  105,  103,  104,  116,  46,  32,  65,  116,  32,  101,  97,  99,  104,  32,  0,  149,  1,  0,  0,  0,  112,  111,  105,  110,  116,  44,  32,  108,  111,  111,  115,  101,  110,  32,  116,  104,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  112,  101,  99,  105,  102,  105,  101,  100,  32,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  0,  149,  7,  0,  0,  0,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  97,  108,  109,  111,  115,  116,  46,  46,  46,  0,  149,  0,  0,  0,  0,  116,  111,  117,  99,  104,  101,  115,  32,  116,  104,  101,  32,  98,  117,  105,  108,  100,  32,  32,  32,  0,  149,  1,  0,  0,  0,  112,  108,  97,  116,  101,  46,  32,  84,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  105,  115,  0,  149,  1,  0,  0,  0,  97,  116,  32,  116,  104,  101,  32,  114,  105,  103,  104,  116,  32,  104,  101,  105,  103,  104,  116,  32,  0,  149,  7,  0,  0,  0,  119,  104,  101,  110,  32,  97,  32,  116,  104,  105,  110,  32,  112,  105,  101,  99,  101,  46,  46,  46,  0,  149,  0,  0,  0,  0,  111,  102,  32,  112,  97,  112,  101,  114,  32,  119,  105,  108,  108,  32,  115,  108,  105,  100,  101,  32,  0,  149,  1,  0,  0,  0,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  32,  0,  149,  1,  0,  0,  0,  97,  110,  100,  32,  98,  117,  105,  108,  100,  32,  112,  108,  97,  116,  101,  32,  119,  105,  116,  104,  0,  149,  7,  0,  0,  0,  32,  115,  111,  109,  101,  32,  102,  114,  105,  99,  116,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  151,  52,  0,  0,  243,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  108,  105,  46,  0,  24,  142,  0,  0,  0,  0,  56,  24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  101,  97,  114,  32,  107,  110,  111,  98,  0,  149,  1,  0,  0,  0,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  106,  117,  115,  116,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  0,  0,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  156,  16,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  42,  45,  0,  24,  142,  155,  16,  0,  0,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  114,  105,  103,  104,  116,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  156,  16,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  100,  239,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  76,  29,  0,  24,  142,  101,  239,  255,  255,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  108,  101,  102,  116,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  100,  239,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  78,  111,  119,  32,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  101,  110,  100,  32,  109,  121,  32,  101,  120,  116,  114,  117,  100,  101,  114,  32,  116,  111,  32,  0,  149,  1,  0,  0,  0,  97,  108,  108,  32,  116,  104,  114,  101,  101,  32,  112,  111,  105,  110,  116,  115,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  97,  103,  97,  105,  110,  32,  116,  111,  32,  114,  101,  99,  104,  101,  99,  107,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  0,  0,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  25,  27,  0,  24,  142,  0,  0,  0,  0,  56,  24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  101,  97,  114,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  0,  0,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  64,  43,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  166,  93,  34,  0,  24,  142,  63,  43,  0,  0,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  114,  105,  103,  104,  116,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  64,  43,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  192,  212,  255,  255,  199,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  192,  198,  45,  0,  24,  142,  193,  212,  255,  255,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  108,  101,  102,  116,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  192,  212,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  145,  59,  26,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  78,  111,  119,  32,  108,  101,  116,  39,  115,  32,  116,  114,  105,  112,  108,  101,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  101,  99,  107,  45,  45,  32,  112,  97,  112,  101,  114,  32,  115,  104,  111,  117,  108,  100,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  32,  98,  101,  116,  119,  101,  101,  110,  32,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  137,  31 };
#	define LEVEL_PLATE_LEN_SINGLE 2102
# define LEVEL_PLATE_DUAL static uint8_t LevelPlateDual[] PROGMEM = { 149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  132,  3,  125,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  151,  52,  0,  0,  243,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  84,  105,  103,  104,  116,  101,  110,  32,  101,  97,  99,  104,  32,  111,  102,  32,  116,  104,  101,  32,  0,  149,  1,  0,  0,  0,  116,  104,  114,  101,  101,  32,  107,  110,  111,  98,  115,  32,  117,  110,  100,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  98,  117,  105,  108,  100,  32,  112,  108,  97,  116,  102,  111,  114,  109,  32,  32,  0,  149,  7,  0,  0,  0,  97,  98,  111,  117,  116,  32,  102,  111,  117,  114,  32,  116,  117,  114,  110,  115,  46,  0,  149,  0,  0,  0,  0,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  109,  111,  118,  101,  32,  109,  121,  0,  149,  1,  0,  0,  0,  101,  120,  116,  114,  117,  100,  101,  114,  32,  97,  114,  111,  117,  110,  100,  32,  116,  111,  32,  32,  0,  149,  1,  0,  0,  0,  100,  105,  102,  102,  101,  114,  101,  110,  116,  32,  112,  111,  105,  110,  116,  115,  32,  115,  111,  32,  0,  149,  7,  0,  0,  0,  121,  111,  117,  32,  99,  97,  110,  32,  99,  104,  101,  99,  107,  46,  46,  46,  0,  149,  0,  0,  0,  0,  116,  104,  101,  32,  104,  101,  105,  103,  104,  116,  46,  32,  65,  116,  32,  101,  97,  99,  104,  32,  0,  149,  1,  0,  0,  0,  112,  111,  105,  110,  116,  44,  32,  108,  111,  111,  115,  101,  110,  32,  116,  104,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  112,  101,  99,  105,  102,  105,  101,  100,  32,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  0,  149,  7,  0,  0,  0,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  97,  108,  109,  111,  115,  116,  46,  46,  46,  0,  149,  0,  0,  0,  0,  116,  111,  117,  99,  104,  101,  115,  32,  116,  104,  101,  32,  98,  117,  105,  108,  100,  32,  32,  32,  0,  149,  1,  0,  0,  0,  112,  108,  97,  116,  101,  46,  32,  84,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  105,  115,  0,  149,  1,  0,  0,  0,  97,  116,  32,  116,  104,  101,  32,  114,  105,  103,  104,  116,  32,  104,  101,  105,  103,  104,  116,  32,  0,  149,  7,  0,  0,  0,  119,  104,  101,  110,  32,  97,  32,  116,  104,  105,  110,  32,  112,  105,  101,  99,  101,  46,  46,  46,  0,  149,  0,  0,  0,  0,  111,  102,  32,  112,  97,  112,  101,  114,  32,  119,  105,  108,  108,  32,  115,  108,  105,  100,  101,  32,  0,  149,  1,  0,  0,  0,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  32,  0,  149,  1,  0,  0,  0,  97,  110,  100,  32,  98,  117,  105,  108,  100,  32,  112,  108,  97,  116,  101,  32,  119,  105,  116,  104,  0,  149,  7,  0,  0,  0,  32,  115,  111,  109,  101,  32,  102,  114,  105,  99,  116,  105,  111,  110,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  151,  52,  0,  0,  242,  25,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  182,  5,  0,  0,  57,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  36,  97,  41,  0,  24,  142,  181,  5,  0,  0,  56,  24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  101,  97,  114,  32,  107,  110,  111,  98,  0,  149,  1,  0,  0,  0,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  106,  117,  115,  116,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  181,  5,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  81,  22,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  42,  45,  0,  24,  142,  81,  22,  0,  0,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  114,  105,  103,  104,  116,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  81,  22,  0,  0,  199,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  105,  244,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  63,  232,  29,  0,  24,  142,  105,  244,  255,  255,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  108,  101,  102,  116,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  105,  244,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  78,  111,  119,  32,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  115,  101,  110,  100,  32,  109,  121,  32,  101,  120,  116,  114,  117,  100,  101,  114,  32,  116,  111,  32,  0,  149,  1,  0,  0,  0,  97,  108,  108,  32,  116,  104,  114,  101,  101,  32,  112,  111,  105,  110,  116,  115,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  97,  103,  97,  105,  110,  32,  116,  111,  32,  114,  101,  99,  104,  101,  99,  107,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  181,  5,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  120,  56,  27,  0,  24,  142,  182,  5,  0,  0,  56,  24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  101,  97,  114,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  181,  5,  0,  0,  56,  24,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  44,  41,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  90,  197,  31,  0,  24,  142,  45,  41,  0,  0,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  114,  105,  103,  104,  116,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  44,  41,  0,  0,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  18,  226,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  208,  160,  37,  0,  24,  142,  19,  226,  255,  255,  200,  231,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  102,  114,  111,  110,  116,  32,  108,  101,  102,  116,  32,  32,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  18,  226,  255,  255,  200,  231,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  142,  181,  5,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  205,  22,  0,  24,  142,  182,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  224,  147,  4,  0,  24,  149,  0,  0,  0,  0,  78,  111,  119,  32,  108,  101,  116,  39,  115,  32,  116,  114,  105,  112,  108,  101,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  99,  104,  101,  99,  107,  45,  45,  32,  112,  97,  112,  101,  114,  32,  115,  104,  111,  117,  108,  100,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  32,  98,  101,  116,  119,  101,  101,  110,  32,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  137,  31 };
#	define LEVEL_PLATE_LEN_DUAL 2102
#else
# define LEVEL_PLATE_SINGLE static uint8_t LevelPlateSingle[] PROGMEM = { 149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  70,  105,  110,  100,  32,  116,  104,  101,  32,  52,  32,  107,  110,  111,  98,  115,  32,  111,  110,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  98,  111,  116,  116,  111,  110,  32,  111,  102,  32,  116,  104,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  112,  108,  97,  116,  102,  111,  114,  109,  32,  97,  110,  100,  32,  116,  105,  103,  104,  116,  101,  110,  0,  149,  7,  0,  0,  0,  102,  111,  117,  114,  32,  111,  114,  32,  102,  105,  118,  101,  32,  116,  117,  114,  110,  115,  46,  0,  149,  0,  0,  0,  0,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  109,  111,  118,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  101,  120,  116,  114,  117,  100,  101,  114,  32,  116,  111,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  118,  97,  114,  105,  111,  117,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  32,  32,  32,  0,  149,  7,  0,  0,  0,  102,  111,  114,  32,  97,  100,  106,  117,  115,  116,  109,  101,  110,  116,  46,  0,  149,  0,  0,  0,  0,  73,  110,  32,  101,  97,  99,  104,  32,  112,  111,  115,  105,  116,  105,  111,  110,  44,  32,  32,  32,  0,  149,  1,  0,  0,  0,  119,  101,  32,  119,  105,  108,  108,  32,  110,  101,  101,  100,  32,  116,  111,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  97,  100,  106,  117,  115,  116,  32,  50,  32,  107,  110,  111,  98,  115,  32,  97,  116,  32,  32,  32,  0,  149,  7,  0,  0,  0,  116,  104,  101,  32,  115,  97,  109,  101,  32,  116,  105,  109,  101,  46,  0,  149,  0,  0,  0,  0,  78,  111,  122,  122,  108,  101,  115,  32,  97,  114,  101,  32,  97,  116,  32,  116,  104,  101,  32,  32,  0,  149,  1,  0,  0,  0,  114,  105,  103,  104,  116,  32,  104,  101,  105,  103,  104,  116,  32,  119,  104,  101,  110,  32,  32,  32,  0,  149,  1,  0,  0,  0,  121,  111,  117,  32,  99,  97,  110,  32,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  32,  97,  0,  149,  7,  0,  0,  0,  115,  104,  101,  101,  116,  32,  111,  102,  32,  112,  97,  112,  101,  114,  0,  149,  0,  0,  0,  0,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  32,  0,  149,  1,  0,  0,  0,  97,  110,  100,  32,  116,  104,  101,  32,  112,  108,  97,  116,  101,  46,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  71,  114,  97,  98,  32,  97,  32,  115,  104,  101,  101,  116,  32,  111,  102,  32,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  97,  112,  101,  114,  32,  116,  111,  32,  97,  115,  115,  105,  115,  116,  32,  117,  115,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  230,  55,  0,  0,  149,  27,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  42,  13,  59,  0,  24,  142,  0,  0,  0,  0,  201,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  102,  114,  111,  110,  116,  32,  116,  119,  111,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  0,  0,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  81,  129,  40,  0,  24,  142,  0,  0,  0,  0,  122,  26,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  98,  97,  99,  107,  32,  116,  119,  111,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  0,  0,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  198,  36,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  168,  47,  34,  0,  24,  142,  198,  36,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  105,  103,  104,  116,  32,  116,  119,  111,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  198,  36,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  58,  219,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  139,  124,  55,  0,  24,  142,  58,  219,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  108,  101,  102,  116,  32,  116,  119,  111,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  58,  219,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  69,  190,  27,  0,  24,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  67,  104,  101,  99,  107,  32,  116,  104,  97,  116,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_SINGLE 1578
# define LEVEL_PLATE_DUAL static uint8_t LevelPlateDual[] PROGMEM = { 149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  149,  0,  0,  0,  0,  70,  105,  110,  100,  32,  116,  104,  101,  32,  52,  32,  107,  110,  111,  98,  115,  32,  111,  110,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  98,  111,  116,  116,  111,  110,  32,  111,  102,  32,  116,  104,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  112,  108,  97,  116,  102,  111,  114,  109,  32,  97,  110,  100,  32,  116,  105,  103,  104,  116,  101,  110,  0,  149,  7,  0,  0,  0,  102,  111,  117,  114,  32,  111,  114,  32,  102,  105,  118,  101,  32,  116,  117,  114,  110,  115,  46,  0,  149,  0,  0,  0,  0,  73,  39,  109,  32,  103,  111,  105,  110,  103,  32,  116,  111,  32,  109,  111,  118,  101,  32,  32,  32,  0,  149,  1,  0,  0,  0,  116,  104,  101,  32,  101,  120,  116,  114,  117,  100,  101,  114,  32,  116,  111,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  118,  97,  114,  105,  111,  117,  115,  32,  112,  111,  115,  105,  116,  105,  111,  110,  115,  32,  32,  32,  0,  149,  7,  0,  0,  0,  102,  111,  114,  32,  97,  100,  106,  117,  115,  116,  109,  101,  110,  116,  46,  0,  149,  0,  0,  0,  0,  73,  110,  32,  101,  97,  99,  104,  32,  112,  111,  115,  105,  116,  105,  111,  110,  44,  32,  32,  32,  0,  149,  1,  0,  0,  0,  119,  101,  32,  119,  105,  108,  108,  32,  110,  101,  101,  100,  32,  116,  111,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  97,  100,  106,  117,  115,  116,  32,  50,  32,  107,  110,  111,  98,  115,  32,  97,  116,  32,  32,  32,  0,  149,  7,  0,  0,  0,  116,  104,  101,  32,  115,  97,  109,  101,  32,  116,  105,  109,  101,  46,  0,  149,  0,  0,  0,  0,  78,  111,  122,  122,  108,  101,  115,  32,  97,  114,  101,  32,  97,  116,  32,  116,  104,  101,  32,  32,  0,  149,  1,  0,  0,  0,  114,  105,  103,  104,  116,  32,  104,  101,  105,  103,  104,  116,  32,  119,  104,  101,  110,  32,  32,  32,  0,  149,  1,  0,  0,  0,  121,  111,  117,  32,  99,  97,  110,  32,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  32,  97,  0,  149,  7,  0,  0,  0,  115,  104,  101,  101,  116,  32,  111,  102,  32,  112,  97,  112,  101,  114,  0,  149,  0,  0,  0,  0,  98,  101,  116,  119,  101,  101,  110,  32,  116,  104,  101,  32,  110,  111,  122,  122,  108,  101,  32,  32,  0,  149,  1,  0,  0,  0,  97,  110,  100,  32,  116,  104,  101,  32,  112,  108,  97,  116,  101,  46,  32,  32,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  71,  114,  97,  98,  32,  97,  32,  115,  104,  101,  101,  116,  32,  111,  102,  32,  32,  32,  32,  32,  0,  149,  7,  0,  0,  0,  112,  97,  112,  101,  114,  32,  116,  111,  32,  97,  115,  115,  105,  115,  116,  32,  117,  115,  46,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  229,  55,  0,  0,  148,  27,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  17,  6,  0,  0,  202,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  218,  223,  55,  0,  24,  142,  18,  6,  0,  0,  202,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  102,  114,  111,  110,  116,  32,  116,  119,  111,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  17,  6,  0,  0,  201,  228,  255,  255,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  17,  6,  0,  0,  123,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  81,  129,  40,  0,  24,  142,  17,  6,  0,  0,  122,  26,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  98,  97,  99,  107,  32,  116,  119,  111,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  18,  6,  0,  0,  122,  26,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  42,  39,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  207,  249,  31,  0,  24,  142,  42,  39,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  114,  105,  103,  104,  116,  32,  116,  119,  111,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  41,  39,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  249,  228,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  23,  240,  49,  0,  24,  142,  249,  228,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  65,  100,  106,  117,  115,  116,  32,  116,  104,  101,  32,  108,  101,  102,  116,  32,  116,  119,  111,  32,  0,  149,  1,  0,  0,  0,  107,  110,  111,  98,  115,  32,  117,  110,  116,  105,  108,  32,  112,  97,  112,  101,  114,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  0,  142,  249,  228,  255,  255,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  142,  17,  6,  0,  0,  0,  0,  0,  0,  208,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  11,  248,  24,  0,  24,  142,  17,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  154,  233,  3,  0,  24,  149,  0,  0,  0,  0,  67,  104,  101,  99,  107,  32,  116,  104,  97,  116,  32,  112,  97,  112,  101,  114,  32,  32,  32,  32,  0,  149,  1,  0,  0,  0,  106,  117,  115,  116,  32,  115,  108,  105,  100,  101,  115,  32,  98,  101,  116,  119,  101,  101,  110,  32,  0,  149,  7,  0,  0,  0,  110,  111,  122,  122,  108,  101,  32,  97,  110,  100,  32,  112,  108,  97,  116,  101,  0,  137,  31 };
# define LEVEL_PLATE_LEN_DUAL 1578
#endif

/// the home axes script homes the XYZ axes and recalls home positions
#define HOME_AXES_SCRIPT static uint8_t HomeAxes[] PROGMEM = { 149,  2,  0,  0,  0,  80,  108,  101,  97,  115,  101,  32,  119,  97,  105,  116,  46,  46,  46,  0,  132,  3,  105,  1,  0,  0,  20,  0,  131,  4,  136,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  142,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  87,  41,  4,  0,  24,  131,  4,  220,  5,  0,  0,  20,  0,  144,  31,  137,  31 };
#define HOME_AXES_SCRIPT_LEN 95

#endif //end of default ELSE for US English */


/// the gcode and s3g files for these scripts are located in firmware/s3g_scripts
/// the script loadDataFile.py converts s3g files to byte arrays to store in PROGMEM

/// the nozzle calibration script walks users through a procedure to calibrate the two nozzles on a dual extrusion machine
#ifdef MODEL_REPLICATOR2
# define NOZZLE_CALIBRATE static uint8_t NozzleCalibrate[] PROGMEM = { 153,  0,  0,  0,  0,  110,  111,  122,  122,  108,  101,  67,  97,  108,  105,  98,  114,  97,  116,  105,  111,  110,  0,  150,  0,  0,  134,  0,  132,  3,  82,  1,  0,  0,  20,  0,  131,  4,  166,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  139,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  166,  0,  0,  0,  131,  4,  220,  5,  0,  0,  20,  0,  144,  31,  140,  151,  52,  0,  0,  242,  25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  139,  64,  217,  255,  255,  191,  230,  255,  255,  96,  234,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  0,  0,  0,  145,  1,  20,  145,  0,  20,  145,  4,  20,  145,  3,  20,  136,  0,  31,  2,  110,  0,  141,  0,  100,  0,  88,  2,  136,  0,  3,  2,  230,  0,  136,  1,  3,  2,  230,  0,  135,  0,  100,  0,  88,  2,  135,  1,  100,  0,  88,  2,  145,  1,  127,  145,  0,  127,  145,  4,  127,  145,  3,  127,  139,  200,  231,  255,  255,  9,  235,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  0,  0,  0,  139,  200,  231,  255,  255,  9,  235,  255,  255,  104,  1,  0,  0,  228,  255,  255,  255,  0,  0,  0,  0,  12,  3,  0,  0,  139,  200,  231,  255,  255,  9,  235,  255,  255,  240,  0,  0,  0,  208,  255,  255,  255,  0,  0,  0,  0,  62,  0,  0,  0,  139,  200,  231,  255,  255,  9,  235,  255,  255,  240,  0,  0,  0,  179,  255,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  241,  217,  255,  255,  9,  235,  255,  255,  240,  0,  0,  0,  79,  254,  255,  255,  0,  0,  0,  0,  127,  3,  0,  0,  139,  200,  231,  255,  255,  136,  238,  255,  255,  240,  0,  0,  0,  127,  254,  255,  255,  0,  0,  0,  0,  211,  0,  0,  0,  139,  200,  231,  255,  255,  136,  238,  255,  255,  240,  0,  0,  0,  99,  254,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  136,  238,  255,  255,  240,  0,  0,  0,  254,  252,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  6,  242,  255,  255,  240,  0,  0,  0,  46,  253,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  6,  242,  255,  255,  240,  0,  0,  0,  18,  253,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  6,  242,  255,  255,  240,  0,  0,  0,  173,  251,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  133,  245,  255,  255,  240,  0,  0,  0,  221,  251,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  133,  245,  255,  255,  240,  0,  0,  0,  193,  251,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  133,  245,  255,  255,  240,  0,  0,  0,  92,  250,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  3,  249,  255,  255,  240,  0,  0,  0,  141,  250,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  3,  249,  255,  255,  240,  0,  0,  0,  112,  250,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  3,  249,  255,  255,  240,  0,  0,  0,  11,  249,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  130,  252,  255,  255,  240,  0,  0,  0,  60,  249,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  130,  252,  255,  255,  240,  0,  0,  0,  31,  249,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  130,  252,  255,  255,  240,  0,  0,  0,  186,  247,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  235,  247,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  206,  247,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  105,  246,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  126,  3,  0,  0,  240,  0,  0,  0,  154,  246,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  126,  3,  0,  0,  240,  0,  0,  0,  125,  246,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  126,  3,  0,  0,  240,  0,  0,  0,  25,  245,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  253,  6,  0,  0,  240,  0,  0,  0,  73,  245,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  253,  6,  0,  0,  240,  0,  0,  0,  44,  245,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  253,  6,  0,  0,  240,  0,  0,  0,  200,  243,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  123,  10,  0,  0,  240,  0,  0,  0,  248,  243,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  123,  10,  0,  0,  240,  0,  0,  0,  219,  243,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  123,  10,  0,  0,  240,  0,  0,  0,  119,  242,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  250,  13,  0,  0,  240,  0,  0,  0,  167,  242,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  250,  13,  0,  0,  240,  0,  0,  0,  138,  242,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  250,  13,  0,  0,  240,  0,  0,  0,  38,  241,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  120,  17,  0,  0,  240,  0,  0,  0,  86,  241,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  120,  17,  0,  0,  240,  0,  0,  0,  57,  241,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  120,  17,  0,  0,  240,  0,  0,  0,  213,  239,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  200,  231,  255,  255,  247,  20,  0,  0,  240,  0,  0,  0,  5,  240,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  200,  231,  255,  255,  247,  20,  0,  0,  240,  0,  0,  0,  232,  239,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  221,  255,  255,  247,  20,  0,  0,  240,  0,  0,  0,  132,  238,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  106,  245,  255,  255,  21,  249,  255,  255,  104,  1,  0,  0,  180,  238,  255,  255,  0,  0,  0,  0,  14,  1,  0,  0,  139,  106,  245,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  132,  238,  255,  255,  0,  0,  0,  0,  156,  0,  0,  0,  139,  106,  245,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  103,  238,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  106,  245,  255,  255,  235,  6,  0,  0,  240,  0,  0,  0,  3,  237,  255,  255,  0,  0,  0,  0,  127,  3,  0,  0,  139,  233,  248,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  51,  237,  255,  255,  0,  0,  0,  0,  211,  0,  0,  0,  139,  233,  248,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  22,  237,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  233,  248,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  178,  235,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  103,  252,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  226,  235,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  103,  252,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  197,  235,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  103,  252,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  97,  234,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  230,  255,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  145,  234,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  230,  255,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  116,  234,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  230,  255,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  16,  233,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  100,  3,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  64,  233,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  100,  3,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  35,  233,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  100,  3,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  191,  231,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  226,  6,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  239,  231,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  226,  6,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  210,  231,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  226,  6,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  110,  230,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  97,  10,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  158,  230,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  97,  10,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  129,  230,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  97,  10,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  29,  229,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  223,  13,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  77,  229,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  223,  13,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  48,  229,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  223,  13,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  204,  227,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  94,  17,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  252,  227,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  94,  17,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  223,  227,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  94,  17,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  123,  226,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  220,  20,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  171,  226,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  220,  20,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  142,  226,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  220,  20,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  42,  225,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  91,  24,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  90,  225,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  91,  24,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  61,  225,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  91,  24,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  217,  223,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  218,  27,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  9,  224,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  218,  27,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  236,  223,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  218,  27,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  136,  222,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  88,  31,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  184,  222,  255,  255,  0,  0,  0,  0,  216,  0,  0,  0,  139,  88,  31,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  155,  222,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  88,  31,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  55,  221,  255,  255,  0,  0,  0,  0,  130,  3,  0,  0,  139,  88,  31,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  103,  221,  255,  255,  0,  0,  0,  0,  12,  3,  0,  0,  140,  88,  31,  0,  0,  117,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  134,  1,  137,  24,  139,  200,  231,  255,  255,  62,  235,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  223,  0,  0,  0,  139,  200,  231,  255,  255,  62,  235,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  228,  255,  255,  255,  12,  3,  0,  0,  139,  200,  231,  255,  255,  62,  235,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  208,  255,  255,  255,  62,  0,  0,  0,  139,  200,  231,  255,  255,  62,  235,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  179,  255,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  62,  235,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  79,  254,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  127,  254,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  99,  254,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  254,  252,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  42,  242,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  46,  253,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  42,  242,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  18,  253,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  42,  242,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  173,  251,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  159,  245,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  221,  251,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  159,  245,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  193,  251,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  159,  245,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  92,  250,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  141,  250,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  112,  250,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  11,  249,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  139,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  60,  249,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  139,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  31,  249,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  139,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  186,  247,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  235,  247,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  206,  247,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  105,  246,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  154,  246,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  125,  246,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  117,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  25,  245,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  235,  6,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  73,  245,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  235,  6,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  44,  245,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  235,  6,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  200,  243,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  97,  10,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  248,  243,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  97,  10,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  219,  243,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  97,  10,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  119,  242,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  214,  13,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  167,  242,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  214,  13,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  138,  242,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  214,  13,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  38,  241,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  76,  17,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  86,  241,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  76,  17,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  57,  241,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  76,  17,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  213,  239,  255,  255,  130,  3,  0,  0,  139,  200,  231,  255,  255,  194,  20,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  5,  240,  255,  255,  216,  0,  0,  0,  139,  200,  231,  255,  255,  194,  20,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  232,  239,  255,  255,  133,  1,  0,  0,  139,  42,  242,  255,  255,  194,  20,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  132,  238,  255,  255,  130,  3,  0,  0,  139,  159,  245,  255,  255,  180,  238,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  180,  238,  255,  255,  206,  0,  0,  0,  139,  159,  245,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  132,  238,  255,  255,  156,  0,  0,  0,  139,  159,  245,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  103,  238,  255,  255,  133,  1,  0,  0,  139,  159,  245,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  3,  237,  255,  255,  130,  3,  0,  0,  139,  21,  249,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  51,  237,  255,  255,  216,  0,  0,  0,  139,  21,  249,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  22,  237,  255,  255,  133,  1,  0,  0,  139,  21,  249,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  178,  235,  255,  255,  130,  3,  0,  0,  139,  139,  252,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  226,  235,  255,  255,  216,  0,  0,  0,  139,  139,  252,  255,  255,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  197,  235,  255,  255,  133,  1,  0,  0,  139,  139,  252,  255,  255,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  97,  234,  255,  255,  130,  3,  0,  0,  139,  0,  0,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  145,  234,  255,  255,  216,  0,  0,  0,  139,  0,  0,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  116,  234,  255,  255,  133,  1,  0,  0,  139,  0,  0,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  16,  233,  255,  255,  130,  3,  0,  0,  139,  117,  3,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  64,  233,  255,  255,  216,  0,  0,  0,  139,  117,  3,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  35,  233,  255,  255,  133,  1,  0,  0,  139,  117,  3,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  191,  231,  255,  255,  130,  3,  0,  0,  139,  235,  6,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  239,  231,  255,  255,  216,  0,  0,  0,  139,  235,  6,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  210,  231,  255,  255,  133,  1,  0,  0,  139,  235,  6,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  110,  230,  255,  255,  130,  3,  0,  0,  139,  97,  10,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  158,  230,  255,  255,  216,  0,  0,  0,  139,  97,  10,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  129,  230,  255,  255,  133,  1,  0,  0,  139,  97,  10,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  29,  229,  255,  255,  130,  3,  0,  0,  139,  214,  13,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  77,  229,  255,  255,  216,  0,  0,  0,  139,  214,  13,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  48,  229,  255,  255,  133,  1,  0,  0,  139,  214,  13,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  204,  227,  255,  255,  130,  3,  0,  0,  139,  76,  17,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  252,  227,  255,  255,  216,  0,  0,  0,  139,  76,  17,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  223,  227,  255,  255,  133,  1,  0,  0,  139,  76,  17,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  123,  226,  255,  255,  130,  3,  0,  0,  139,  194,  20,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  171,  226,  255,  255,  216,  0,  0,  0,  139,  194,  20,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  142,  226,  255,  255,  133,  1,  0,  0,  139,  194,  20,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  42,  225,  255,  255,  130,  3,  0,  0,  139,  56,  24,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  90,  225,  255,  255,  216,  0,  0,  0,  139,  56,  24,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  61,  225,  255,  255,  133,  1,  0,  0,  139,  56,  24,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  217,  223,  255,  255,  130,  3,  0,  0,  139,  173,  27,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  9,  224,  255,  255,  216,  0,  0,  0,  139,  173,  27,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  236,  223,  255,  255,  133,  1,  0,  0,  139,  173,  27,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  136,  222,  255,  255,  130,  3,  0,  0,  139,  35,  31,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  184,  222,  255,  255,  216,  0,  0,  0,  139,  35,  31,  0,  0,  180,  238,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  155,  222,  255,  255,  133,  1,  0,  0,  139,  35,  31,  0,  0,  21,  249,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  55,  221,  255,  255,  130,  3,  0,  0,  139,  35,  31,  0,  0,  21,  249,  255,  255,  48,  242,  0,  0,  0,  0,  0,  0,  55,  221,  255,  255,  197,  0,  0,  0,  137,  0,  136,  0,  3,  2,  0,  0,  136,  1,  3,  2,  0,  0,  136,  0,  31,  2,  0,  0 };
#else
# define NOZZLE_CALIBRATE static uint8_t NozzleCalibrate[] PROGMEM = { 153,  0,  0,  0,  0,  110,  111,  122,  122,  108,  101,  67,  97,  108,  105,  98,  114,  97,  116,  105,  111,  110,  0,  150,  0,  0,  134,  0,  132,  3,  62,  1,  0,  0,  20,  0,  131,  4,  166,  0,  0,  0,  20,  0,  140,  0,  0,  0,  0,  0,  0,  0,  0,  48,  248,  255,  255,  0,  0,  0,  0,  0,  0,  0,  0,  139,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  166,  0,  0,  0,  131,  4,  220,  5,  0,  0,  20,  0,  144,  31,  140,  229,  55,  0,  0,  148,  27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  139,  209,  214,  255,  255,  40,  229,  255,  255,  96,  234,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  0,  0,  0,  145,  1,  20,  145,  0,  20,  145,  4,  20,  145,  3,  20,  136,  0,  31,  2,  110,  0,  141,  0,  100,  0,  88,  2,  136,  0,  3,  2,  230,  0,  136,  1,  3,  2,  230,  0,  135,  0,  100,  0,  88,  2,  135,  1,  100,  0,  88,  2,  145,  1,  127,  145,  0,  127,  145,  4,  127,  145,  3,  127,  139,  67,  230,  255,  255,  184,  233,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  128,  0,  0,  0,  139,  67,  230,  255,  255,  184,  233,  255,  255,  104,  1,  0,  0,  228,  255,  255,  255,  0,  0,  0,  0,  12,  3,  0,  0,  139,  67,  230,  255,  255,  184,  233,  255,  255,  240,  0,  0,  0,  208,  255,  255,  255,  0,  0,  0,  0,  62,  0,  0,  0,  139,  67,  230,  255,  255,  184,  233,  255,  255,  240,  0,  0,  0,  179,  255,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  141,  215,  255,  255,  184,  233,  255,  255,  240,  0,  0,  0,  79,  254,  255,  255,  0,  0,  0,  0,  74,  3,  0,  0,  139,  67,  230,  255,  255,  110,  237,  255,  255,  240,  0,  0,  0,  127,  254,  255,  255,  0,  0,  0,  0,  199,  0,  0,  0,  139,  67,  230,  255,  255,  110,  237,  255,  255,  240,  0,  0,  0,  99,  254,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  110,  237,  255,  255,  240,  0,  0,  0,  254,  252,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  37,  241,  255,  255,  240,  0,  0,  0,  46,  253,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  37,  241,  255,  255,  240,  0,  0,  0,  18,  253,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  37,  241,  255,  255,  240,  0,  0,  0,  173,  251,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  220,  244,  255,  255,  240,  0,  0,  0,  221,  251,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  220,  244,  255,  255,  240,  0,  0,  0,  193,  251,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  220,  244,  255,  255,  240,  0,  0,  0,  92,  250,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  147,  248,  255,  255,  240,  0,  0,  0,  141,  250,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  147,  248,  255,  255,  240,  0,  0,  0,  112,  250,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  147,  248,  255,  255,  240,  0,  0,  0,  11,  249,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  74,  252,  255,  255,  240,  0,  0,  0,  60,  249,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  74,  252,  255,  255,  240,  0,  0,  0,  31,  249,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  74,  252,  255,  255,  240,  0,  0,  0,  186,  247,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  235,  247,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  206,  247,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  105,  246,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  182,  3,  0,  0,  240,  0,  0,  0,  154,  246,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  182,  3,  0,  0,  240,  0,  0,  0,  125,  246,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  182,  3,  0,  0,  240,  0,  0,  0,  25,  245,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  109,  7,  0,  0,  240,  0,  0,  0,  73,  245,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  109,  7,  0,  0,  240,  0,  0,  0,  44,  245,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  109,  7,  0,  0,  240,  0,  0,  0,  200,  243,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  36,  11,  0,  0,  240,  0,  0,  0,  248,  243,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  36,  11,  0,  0,  240,  0,  0,  0,  219,  243,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  36,  11,  0,  0,  240,  0,  0,  0,  119,  242,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  219,  14,  0,  0,  240,  0,  0,  0,  167,  242,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  219,  14,  0,  0,  240,  0,  0,  0,  138,  242,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  219,  14,  0,  0,  240,  0,  0,  0,  38,  241,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  146,  18,  0,  0,  240,  0,  0,  0,  86,  241,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  146,  18,  0,  0,  240,  0,  0,  0,  57,  241,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  146,  18,  0,  0,  240,  0,  0,  0,  213,  239,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  67,  230,  255,  255,  72,  22,  0,  0,  240,  0,  0,  0,  5,  240,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  67,  230,  255,  255,  72,  22,  0,  0,  240,  0,  0,  0,  232,  239,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  59,  219,  255,  255,  72,  22,  0,  0,  240,  0,  0,  0,  132,  238,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  192,  244,  255,  255,  166,  248,  255,  255,  104,  1,  0,  0,  180,  238,  255,  255,  0,  0,  0,  0,  254,  0,  0,  0,  139,  192,  244,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  132,  238,  255,  255,  0,  0,  0,  0,  156,  0,  0,  0,  139,  192,  244,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  103,  238,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  192,  244,  255,  255,  90,  7,  0,  0,  240,  0,  0,  0,  3,  237,  255,  255,  0,  0,  0,  0,  74,  3,  0,  0,  139,  119,  248,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  51,  237,  255,  255,  0,  0,  0,  0,  199,  0,  0,  0,  139,  119,  248,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  22,  237,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  119,  248,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  178,  235,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  45,  252,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  226,  235,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  45,  252,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  197,  235,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  45,  252,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  97,  234,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  228,  255,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  145,  234,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  228,  255,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  116,  234,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  228,  255,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  16,  233,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  154,  3,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  64,  233,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  154,  3,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  35,  233,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  154,  3,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  191,  231,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  81,  7,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  239,  231,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  81,  7,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  210,  231,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  81,  7,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  110,  230,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  8,  11,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  158,  230,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  8,  11,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  129,  230,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  8,  11,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  29,  229,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  191,  14,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  77,  229,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  191,  14,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  48,  229,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  191,  14,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  204,  227,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  117,  18,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  252,  227,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  117,  18,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  223,  227,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  117,  18,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  123,  226,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  44,  22,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  171,  226,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  44,  22,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  142,  226,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  44,  22,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  42,  225,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  227,  25,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  90,  225,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  227,  25,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  61,  225,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  227,  25,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  217,  223,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  154,  29,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  9,  224,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  154,  29,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  236,  223,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  154,  29,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  136,  222,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  81,  33,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  184,  222,  255,  255,  0,  0,  0,  0,  203,  0,  0,  0,  139,  81,  33,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  155,  222,  255,  255,  0,  0,  0,  0,  133,  1,  0,  0,  139,  81,  33,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  55,  221,  255,  255,  0,  0,  0,  0,  76,  3,  0,  0,  139,  81,  33,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  103,  221,  255,  255,  0,  0,  0,  0,  12,  3,  0,  0,  140,  81,  33,  0,  0,  173,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  134,  1,  137,  24,  139,  67,  230,  255,  255,  240,  233,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  210,  0,  0,  0,  139,  67,  230,  255,  255,  240,  233,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  228,  255,  255,  255,  12,  3,  0,  0,  139,  67,  230,  255,  255,  240,  233,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  208,  255,  255,  255,  62,  0,  0,  0,  139,  67,  230,  255,  255,  240,  233,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  179,  255,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  240,  233,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  79,  254,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  127,  254,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  99,  254,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  254,  252,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  75,  241,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  46,  253,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  75,  241,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  18,  253,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  75,  241,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  173,  251,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  248,  244,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  221,  251,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  248,  244,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  193,  251,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  248,  244,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  92,  250,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  141,  250,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  112,  250,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  11,  249,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  83,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  60,  249,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  83,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  31,  249,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  83,  252,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  186,  247,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  235,  247,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  206,  247,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  0,  0,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  105,  246,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  154,  246,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  125,  246,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  173,  3,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  25,  245,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  90,  7,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  73,  245,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  90,  7,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  44,  245,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  90,  7,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  200,  243,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  8,  11,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  248,  243,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  8,  11,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  219,  243,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  8,  11,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  119,  242,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  181,  14,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  167,  242,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  181,  14,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  138,  242,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  181,  14,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  38,  241,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  98,  18,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  86,  241,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  98,  18,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  57,  241,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  98,  18,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  213,  239,  255,  255,  76,  3,  0,  0,  139,  67,  230,  255,  255,  16,  22,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  5,  240,  255,  255,  203,  0,  0,  0,  139,  67,  230,  255,  255,  16,  22,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  232,  239,  255,  255,  133,  1,  0,  0,  139,  75,  241,  255,  255,  16,  22,  0,  0,  240,  0,  0,  0,  0,  0,  0,  0,  132,  238,  255,  255,  76,  3,  0,  0,  139,  248,  244,  255,  255,  158,  237,  255,  255,  104,  1,  0,  0,  0,  0,  0,  0,  180,  238,  255,  255,  193,  0,  0,  0,  139,  248,  244,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  132,  238,  255,  255,  156,  0,  0,  0,  139,  248,  244,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  103,  238,  255,  255,  133,  1,  0,  0,  139,  248,  244,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  3,  237,  255,  255,  76,  3,  0,  0,  139,  166,  248,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  51,  237,  255,  255,  203,  0,  0,  0,  139,  166,  248,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  22,  237,  255,  255,  133,  1,  0,  0,  139,  166,  248,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  178,  235,  255,  255,  76,  3,  0,  0,  139,  83,  252,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  226,  235,  255,  255,  203,  0,  0,  0,  139,  83,  252,  255,  255,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  197,  235,  255,  255,  133,  1,  0,  0,  139,  83,  252,  255,  255,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  97,  234,  255,  255,  76,  3,  0,  0,  139,  0,  0,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  145,  234,  255,  255,  203,  0,  0,  0,  139,  0,  0,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  116,  234,  255,  255,  133,  1,  0,  0,  139,  0,  0,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  16,  233,  255,  255,  76,  3,  0,  0,  139,  173,  3,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  64,  233,  255,  255,  203,  0,  0,  0,  139,  173,  3,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  35,  233,  255,  255,  133,  1,  0,  0,  139,  173,  3,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  191,  231,  255,  255,  76,  3,  0,  0,  139,  90,  7,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  239,  231,  255,  255,  203,  0,  0,  0,  139,  90,  7,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  210,  231,  255,  255,  133,  1,  0,  0,  139,  90,  7,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  110,  230,  255,  255,  76,  3,  0,  0,  139,  8,  11,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  158,  230,  255,  255,  203,  0,  0,  0,  139,  8,  11,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  129,  230,  255,  255,  133,  1,  0,  0,  139,  8,  11,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  29,  229,  255,  255,  76,  3,  0,  0,  139,  181,  14,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  77,  229,  255,  255,  203,  0,  0,  0,  139,  181,  14,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  48,  229,  255,  255,  133,  1,  0,  0,  139,  181,  14,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  204,  227,  255,  255,  76,  3,  0,  0,  139,  98,  18,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  252,  227,  255,  255,  203,  0,  0,  0,  139,  98,  18,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  223,  227,  255,  255,  133,  1,  0,  0,  139,  98,  18,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  123,  226,  255,  255,  76,  3,  0,  0,  139,  16,  22,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  171,  226,  255,  255,  203,  0,  0,  0,  139,  16,  22,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  142,  226,  255,  255,  133,  1,  0,  0,  139,  16,  22,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  42,  225,  255,  255,  76,  3,  0,  0,  139,  189,  25,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  90,  225,  255,  255,  203,  0,  0,  0,  139,  189,  25,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  61,  225,  255,  255,  133,  1,  0,  0,  139,  189,  25,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  217,  223,  255,  255,  76,  3,  0,  0,  139,  107,  29,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  9,  224,  255,  255,  203,  0,  0,  0,  139,  107,  29,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  236,  223,  255,  255,  133,  1,  0,  0,  139,  107,  29,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  136,  222,  255,  255,  76,  3,  0,  0,  139,  24,  33,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  184,  222,  255,  255,  203,  0,  0,  0,  139,  24,  33,  0,  0,  158,  237,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  155,  222,  255,  255,  133,  1,  0,  0,  139,  24,  33,  0,  0,  166,  248,  255,  255,  240,  0,  0,  0,  0,  0,  0,  0,  55,  221,  255,  255,  76,  3,  0,  0,  139,  24,  33,  0,  0,  166,  248,  255,  255,  48,  242,  0,  0,  0,  0,  0,  0,  55,  221,  255,  255,  197,  0,  0,  0,  137,  0,  136,  0,  3,  2,  0,  0,  136,  1,  3,  2,  0,  0,  136,  0,  31,  2,  0,  0 };
#endif

#endif // __MENU__LOCALES__
