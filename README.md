# watering-system
This is an automatic plant watering system for an Arduino. This is a mostly experimental repository, and the code and board files within may not work correctly.

DO NOT use the code and boards available here for watering plants until version 1.0a is released, or until the boards and code are confirmed to work.



TODO:
(items in **bold** will be dealt with in the next release. Items which have been dealt with are ~~struck through~~.
  * **Add EEPROM-stored settings, which can be changed over the serial port**
  * Add sleep code for lower power consumption
  * Create a lite version for Tiny24 or similar, and another version for 7+ individual plants
  * Create a new board for Mega code. The Mega88 can only work with 6 watering sensors
  * ~~Add individual watering. The code currently uses one pump for both plants~~
  * Replace linear regulator with switching
