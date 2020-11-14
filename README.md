# Serial_Anything
Based on (I2C and SPI) Anything from Nick Gammon, a Serial version to send/receive anything! for Arduino based boards.

You should pay atention to the pins and corresponding number for the Serial connection you are going to use i.e. Serial, Serial1, Serial2, depending on the board you are using; and change the file accordingly. As normal connections from one board to the other,TX to RX, and RX to TX.

## One side sending

```C++
#include "serial_Anything.h"

const int analogInPin = 0;
int sensorValue = 0;

void setup() {
  // initialize 
  Serial1.begin(115200);  
}

void loop() {
  sensorValue = analogRead(analogInPin);  
  serial_writeAnything(sensorValue);
  //no Serial.print because the forming byte inside the lib only works there, uncomment the line inside the .h file  
}
```

## The other receiving

```C++
#include "serial_Anything.h"
int sensorValue = 0 ;

void setup() {
  // initialize both serial ports:
  //Serial.begin(9600); // Uncomment and change number the line below to check here on monitor
  Serial.begin(115200); // Serial to SerialX and also on the .h file 
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial.available()) { // Also to SerialX if monitor use 
    serial_readAnything(sensorValue);
    //Serial.println(sensorValue); //Uncomment to check the variable change on IDE monitor
  }
}
```
Be sure to not mess with the numbers of the serial ports if monitoring. You should check the [4.Communications/Multiserial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/MultiSerialMega) example to see the use of various serials, whether on the examples on the IDE or Arduino site (link before).

BTW. Making tests, found one can use the same Serial port on IDE's monitor as with the pins, but be sure to disconnect before uploading your sketch (not tested on the receiving side, I might get confused KK).

Please check [Nick Gammon's site](http://www.gammon.com.au/welcome.html), [discussion on I2C](http://www.gammon.com.au/i2c) and [gitHub](https://github.com/nickgammon/I2C_Anything) of the lib's this one is derived from.

Salut!!
