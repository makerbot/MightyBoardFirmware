# Eeprom Map Notation
We notate the eeprom map so that it can be parsed by python and converted to a json map.  The python parser is here: https://github.com/makerbot/s3g/blob/master/makerbot_driver/EEPROM/EepromAnalyzer.py  The purpose of this mapping is to enable the UI to display values to the user and send changes back to the bot.

We comment each line of EepromMap.hh.  Here is an example:

    //$BEGIN_ENTRY
    //$type:H $floating_point:True $constraints:m,0,100 tooltip:here is a tooltip with spaces and no quotes

Start of entry flag:

    BEGIN_ENTRY : a new eeprom map offset entry starts here.  This flag is on its own line

Info flags, all on second comment line:

    type (required): a character in python struct format indicating the data type of the eeprom field 
    floating_point (optional): true if the eeprom field is a float (note we use a fake 16 bit float type) 
    contraints (required): used by eeprom_verifier.py to assess whether the eeprom map contains valid entries. 
        a: any entry could be valid
        m: min/max  followed by two integers in the format min,max
        l: comma separated list of valid options
    units (optional): a string to display on the UI, stating the unit type of the eeprom field
    tooltip (optional):  a description for the entry
    ignore (optional): use this flag for entries that exist but should not be displayed to the user.  Either because they are deprecated, or because they are not changeable.  
    eeprom_map (optional): name the namespace that contains the detail for this entry.  if this option is used, no other flags are required.  eg:
        //$BEGIN_ENTRY
        //$eeprom_map:cooler_eeprom_offsets
    axis_expand (optional): eeprom field is a byte entry representing an XYZAB axis map

   
There are two informational entries in the eeprom_info namespace:

    //$BEGIN_INFO_ENTRY
    //$name:software_variant value:0x01
   
    //$BEGIN_INFO_ENTRY
    //$name:dependent_toolhead_map value:None

     
The first states the software varaint of the eeprom map (see advanced version command in https://github.com/makerbot/s3g/blob/master/doc/s3gProtocol.md)   
The second provides the name of the toolhead eeprom map if applicable.  

More information entries can be added with any number of variable entries, though "name" and "value" are compulsory.
