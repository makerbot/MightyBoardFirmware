
"""
get thermocouple readings from the replicator with a time stamp so we can correlate them to an external reference

Meant to be run from the parent directory of MightyBoardFirmware.  

the s3g directory is assumed to be a sibling of MightyBoardFirmware
"""
import os, sys 
lib_path = os.path.abspath('../')
sys.path.insert(0, lib_path)
lib_path = os.path.abspath('s3g/')
sys.path.insert(0, lib_path)


import optparse
import serial
import io
import struct
import array
import makerbot_driver
import csv
import time

s3g_port = makerbot_driver.s3g()

def GetHeaterReads():
  
  log_file = csv.writer(open(options.filename, 'wb'), delimiter=' ')
  start_time = time.time()

  while 1:
    temps = [time.time()-start_time]
    try:
      if options.platform:
        platform_temp = s3g_port.get_platform_temperature(0)
        temps.append(platform_temp)
        print "platform %d" % (platform_temp)
      if options.toolhead:
        raw_temp = s3g_port.get_toolhead_temperature(int(options.toolhead))
        temps.append(raw_temp)
        print "channel %d %d" % (int(options.toolhead), raw_temp)
      if options.toolhead_two:
        raw_temp_0 =s3g_port.get_toolhead_temperature(int(options.toolhead_two)) 
        temps.append(raw_temp_0)
        print "channel %d %d" % (int(options.toolhead_two), raw_temp_0)
      log_file.writerow(temps)
      time.sleep(0.495)
      
    except (KeyboardInterrupt) :
      return
      
def setUp():
  file = serial.Serial(options.serialPort, '115200', timeout=1)
  s3g_port.writer = makerbot_driver.Writer.StreamWriter(file)
  s3g_port.set_extended_position([0, 0, 0, 0, 0])
  #s3g_port.abort_immediately()
  time.sleep(2)

def tearDown():
  s3g_port.writer.file.close()


if __name__ == '__main__':
  parser = optparse.OptionParser()
  parser.add_option("-p", "--port", dest="serialPort", default="/dev/ttyACM0")
  parser.add_option("-f", "--file", dest="filename", default="temp_data.csv")
  parser.add_option("-t", "--tool", dest="toolhead", default=None, action='store_true')
  parser.add_option("-w", "--tool_two", dest="toolhead_two", default=None,action='store_true')
  parser.add_option("-m", "--platform", dest="platform", default=None,action='store_true')
  (options, args) = parser.parse_args()

  del sys.argv[1:]

  setUp();
 
  GetHeaterReads()
  
  tearDown()
    
