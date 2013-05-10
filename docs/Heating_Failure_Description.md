Heating Failure Description
==========

List of all Heater Errors/Heating Failures broken down by numbers displayed during the Heating Failure! error message on the Replicator 2 and Replicator 2X.


Heating Failure #1
-----

#### Message displayed:

    "Heating Failure #1"  
    "Software Temp Limit"  
    "Reached! Please"  
    "Shutdown or Restart"  

#### Cause:

Temperature above the software predefined limit of 300 degrees C was read over a number of consecutive attempts.

#### Printer Action:

The printer should shut off the heater, cancel the print in progress, and flash lights.


Heating Failure #2
-----

#### Message displayed:

    "Heating Failure #2"  
    "My extruders are not"  
    "heating properly."  
    "Check my connections"  

#### Cause:

We have waited for the software predefined timeout of 90 seconds and did not see the temperature increase by at least 10 degrees C over a number of tries.

#### Printer Action:

The printer should shut off the heater, cancel the print in progress, and flash lights.


Heating Failure #3
-----

#### Message displayed:

    "Heating Failure #3"  
    "My extruders are"  
    "losing temperature."  
    "Check my connections"  

#### Cause:

Temperature has dropped by more than 30 degrees C after it has reached it's set target temperature.

#### Printer Action:

The printer should shut off the heater, cancel the print in progress, and flash lights.

Heating Failure #4
-----

#### Message displayed:

    "Heating Failure #4"  
    "My temperature reads"  
    "are failing! Please"  
    "Check my connections"  

#### Cause:

Thermocouple is either damaged or disconnected on one of the heaters.

#### Printer Action:

The offending heater will be shut off but the print will continue even if the offending heater is used for the print.

Heating Failure #5
-----

#### Message displayed:

    "Heating Failure #5"   
    "I'm reading out of"  
    "range temperatures."  
    "Check my connections"  

#### Cause:

Voltage read from a temperature sensor a number of consecutive times is out of the range of the voltage to temperature translation table.  Something electrical has gone wrong with any of the temperature sensors.

#### Printer Action:

The printer should shut off the heater, cancel the print in progress, and flash lights.

