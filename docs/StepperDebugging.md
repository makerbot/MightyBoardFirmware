#Stepper Debugging
A document to describe how to harvest data from botsteps for stepper debugging.  Unnecessary pausing, abnormal step patterns durion various portions of prints and similar issues can be debugged using the methods described below.

##Bot Step Breakout
Analysis of the Step pins will show when a given stepper motor is being turned by the motherboard.  Solder a lead directly onto this pin, and attach a logic analyzer to it and run a print to see when this motor is stepping.

##Taking some readings
The logic analyzer of choice is the Saleae Logic Analyzer.  Saleae provide a program called Logic (www.saleae.com/downloads) to drive the analyzer.  The data gathered is displayed as a Step Graph, and can be exported to a CSV file for additional processing.  

##Interpreting Data
While information can be parsed out of data gathered with the above methodology, there are several caveats that should be respected:
    * Steps have no notion of acceleration, so attempting to find stepper velocity or build acceleration trapezoids would require modeling the actual stepper you want to look at.
The actual data collected can be visualized as a step graph using the Logic program provided by Soleae.
