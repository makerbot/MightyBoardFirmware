##SD Card Speed Requirements

Note: We should measure both the command processing time and the sd card block read time with the logic analyzer to have a more accurate estimate.  

SD Card Block: 512 Bytes (we read sd card data in blocks at a time)

Command Buffer: 512 Bytes

Extended Move Command: 31 bytes

Moves per Block : 16 moves (512/31)

Approximate time for command processing : 2ms (we should measure this again - this estimate is from memory)

Time to Process 1 block of commands : 32ms (16 *2ms -- subject to check above)

Note: Timing was measured at unknown start/ end points - timing may not be multiplicative, ie only a portion of the time between start,end may be doubling.  So to get accurate times, we may need to measure again.  

Time to read one Block @ 8MHz : 2.5ms

estimated times to read one block at sd card clock speeds :

4MHz    5ms

2MHz    10ms

1MHz    20ms

500kHz  40ms (at this point we are slower than the Time to process 1 block of commands)


Time to send one command with serial interface: 4ms

Time to send 16 commands with serial interface: 64ms


Thus at 250kHz, we are slower than serial transfer (subject to re-measuring the processing and block read times)

Print time tests were done using the nut and bolt print (circular + small features) at 8MHz, 1MHz and 500kHz clock speeds with no appreciable print time difference

