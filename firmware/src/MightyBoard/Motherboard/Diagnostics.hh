/*
 * Copyright 2012 Alison Leonard <alison@makerbot.com>
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
 
 #ifndef DIAGNOSTICS_H
 #define DIAGNOSTICS_H
 
 //#define MOTOR_DIAGNOSTICS
#define HEAT_DIAGNOSTICS
 
namespace testing{
    
    enum heatMode_t{
        HEAT_TEST_BEGIN,
        HEAT_TEST_BUTTON_WAIT,
        HEAT_TEST_CONNECTION_WAIT,
        FAN_TEST,
        FAN_TEST_WAIT,
        HEAT_TEST_TEMP,
        EXTRUDE_TEST,
        EXTRUDE_RUN,
        EXTRUDE_REVERSE,
        HEAT_TEST_DONE,
        HEAT_TEST_QUIT,
        HEAT_TEST_FAIL,
        HEAT_TEST_OFF
    };


    void motorSpin(void);
    void motorTest(void);

    void runHeaterTestsSlice(void);
    void setHeatTestMode(heatMode_t mode, bool single);
    void messageWait(char msg[]);
    void reset(void);

}

#endif
