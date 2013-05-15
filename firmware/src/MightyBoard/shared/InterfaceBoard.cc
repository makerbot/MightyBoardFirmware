#include "InterfaceBoard.hh"
#include "Configuration.hh"
#include "LiquidCrystalSerial.hh"
#include "Host.hh"
#include "Timeout.hh"
#include "Command.hh"
#include "Motherboard.hh"

#if defined HAS_INTERFACE_BOARD

bool onboard_build = false;

InterfaceBoard::InterfaceBoard(ButtonArray& buttons_in,
                               LiquidCrystalSerial& lcd_in):
        lcd(lcd_in),
        buttons(buttons_in),
		waitingMask(0)
{
  buildPercentage = 101;
}

void InterfaceBoard::init() {
	buttons.init();
	
	lcd.begin(LCD_SCREEN_WIDTH, LCD_SCREEN_HEIGHT);
	
	lcd.clear();
	lcd.home();

  building = false;

  screenIndex = -1;
  waitingMask = 0;
  pushScreen(&mainScreen);
  screen_locked = false;
  onboard_build = false;
  onboard_start_idx = 1;
  sd_start_idx = 0;
  user_wait_override = false;
}

void InterfaceBoard::resetLCD() {

	lcd.begin(LCD_SCREEN_WIDTH, LCD_SCREEN_HEIGHT);
}

void InterfaceBoard::doInterrupt() {
	buttons.scanButtons();
}

micros_t InterfaceBoard::getUpdateRate() {
	return screenStack[screenIndex]->getUpdateRate();
}

/// push Error Message Screen
void InterfaceBoard::errorMessage(const unsigned char buf[]){

		messageScreen.clearMessage();
		messageScreen.setXY(0,0);
		messageScreen.addMessage(buf);
		messageScreen.WaitForUser(true);
		if(screenStack[screenIndex] != &messageScreen){
			pushScreen(&messageScreen);
		}else{
			screenStack[screenIndex]->update(lcd, true);
	  }
}

MessageScreen * InterfaceBoard::GetMessageScreen(){
  return &messageScreen;
}

/// pop Error Message Screen
void InterfaceBoard::DoneWithMessage(){

		messageScreen.WaitForUser(false);
		if(screenStack[screenIndex] == &messageScreen){
			popScreen();
		}
}

/// push a local screen
void InterfaceBoard::queueScreen(ScreenType screen){

	
	switch (screen){
		case BUILD_FINISHED:
			pushScreen(&buildFinished);
			break;
		case MESSAGE_SCREEN:
			pushScreen(&messageScreen);
			break;
    case BUILD_SCREEN:
      pushScreen(&buildScreen);
      break;
    case SPLASH_SCREEN:
      pushScreen(&splashScreen);
      break;
    case WELCOME_SCREEN:
      pushScreen(&welcomeScreen);
      break;
    case ACTIVE_BUILD_SCREEN:
      if (screenStack[screenIndex] != &activeScreen){
        pushScreen(&activeScreen);
      }
      break;
    case CHANGE_FILAMENT_SCREEN:
      pushScreen(&filamentScreen);
      break;
		default:
			break;
		}
	
}

/// record screen stack index when onboard script is started so we can return there on finish
void InterfaceBoard::RecordOnboardStartIdx(){
	onboard_start_idx = screenIndex;
}

/// record screen stack index when SD card build is started so we can return there on finish
void InterfaceBoard::RecordSDStartIdx(){
	sd_start_idx = screenIndex;
}

void InterfaceBoard::popToOnboardStart(){
  while(screenIndex > onboard_start_idx){
    popScreenQuick();
  }
  screenStack[screenIndex]->update(lcd, true);
}

void InterfaceBoard::doUpdate() {

		// If we are building, make sure we show a build menu; otherwise,
		// turn it off.
		switch(host::getHostState()) {
		case host::HOST_STATE_BUILDING_ONBOARD:
				onboard_build = true;
		case host::HOST_STATE_BUILDING:
		case host::HOST_STATE_BUILDING_FROM_SD:
			if (!building ){
				/// remove the build finished screen if the user has not done so
				if(screenStack[screenIndex] == &buildFinished){
					popScreen();
				}
				
				// if a screen is waiting for user input, don't push the build screen on top
				// wait until the screen is finished.
        // we do not push the build screen at all for utility scripts that don't require heating.
				if (utility::showMonitor()){
					if(!(((screenStack[screenIndex] == &messageScreen) && messageScreen.screenWaiting()) || command::isWaiting()))
					{
						pushScreen(&buildScreen);
						building = true;
					}
				}else{
					building = true;
				}
				
			}
			break;
		case host::HOST_STATE_HEAT_SHUTDOWN:
			break;
		default:
			if (building) {
        /// don't remove the build screens if there is a message screen waiting or the build Finished screen is on top 
				if(!((screenStack[screenIndex] == &messageScreen) && messageScreen.screenWaiting()) && (screenStack[screenIndex] != &buildFinished)){	
					
					// when using onboard scrips, we want to return to whichever screen we launched the script from
					if(onboard_build){	
						while(screenIndex > onboard_start_idx){
							popScreenQuick();
						}
						screenStack[screenIndex]->update(lcd, true);
						onboard_build = false;
					}
					// else, after a build, we'll want to go back to the main menu
					else{
						while(screenIndex > sd_start_idx){
							popScreenQuick();
						}
						sd_start_idx = 0;
						screenStack[screenIndex]->update(lcd, true);
					}
					building = false;
				}
			}	
			break;
		}
	
	/// check for button pushes and send these to the active screen
	
    static ButtonArray::ButtonName button;

    if(!screen_locked){
        if (buttons.getButton(button)) {
            // respond to button press if waiting
            // pass on to screen if user_wait_override is set (Set by cancel screens)
            if((((1<<button) & waitingMask) != 0) &&
                !user_wait_override){
                 waitingMask = 0;
            } else if (button == ButtonArray::EGG){
                pushScreen(&snakeScreen);
            } else {
                screenStack[screenIndex]->notifyButtonPressed(button);
            }
            // reset user input timeout when buttons are pressed
            Motherboard::getBoard().resetUserInputTimeout();

        }
       
        // update build data
        buildScreen.setBuildPercentage(buildPercentage);	
        screenStack[screenIndex]->update(lcd, false);
    }
}

void InterfaceBoard::setOverride(bool on){
  user_wait_override = on;
}

// push screen to stack and call update
void InterfaceBoard::pushScreen(Screen* newScreen) {
  screen_locked = true;
	if (screenIndex < SCREEN_STACK_DEPTH - 1) {
		screenIndex++;
		screenStack[screenIndex] = newScreen;
	}
  buttons.setButtonDelay(ButtonArray::SlowDelay);
	Motherboard::getBoard().StopProgressBar();
	screenStack[screenIndex]->reset();
  screen_locked = false;
	screenStack[screenIndex]->update(lcd, true);
}

void InterfaceBoard::setBuildPercentage(uint8_t percent){
	
	if(percent < 100){
		buildPercentage = percent;
	}
}

void InterfaceBoard::popScreen() {
	
  screenStack[screenIndex]->pop_actions();
	// Don't allow the root menu to be removed.
	if (screenIndex > 0) {
		screenIndex--;
	}
 
  user_wait_override = false;
  buttons.setButtonDelay(ButtonArray::SlowDelay);
	screenStack[screenIndex]->update(lcd, true);
}

/// pop screen without refreshing the new head screen
void InterfaceBoard::popScreenQuick() {
	
	// Don't allow the root menu to be removed.
	if (screenIndex > 0) {
		screenIndex--;
	}
  buttons.setButtonDelay(ButtonArray::SlowDelay);

}

/// Tell the interface board that the system is waiting for a button push
/// corresponding to one of the bits in the button mask. The interface board
/// will not process button pushes directly until one of the buttons in the
/// mask is pushed.
void InterfaceBoard::waitForButton(uint8_t button_mask) {
  waitingMask = button_mask;
}

/// Check if the expected button push has been made. If waitForButton was
/// never called, always return true.
bool InterfaceBoard::buttonPushed() {
  return waitingMask == 0;
}

#endif
