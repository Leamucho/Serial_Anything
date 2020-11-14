// Modified from Nick Gammon
// May 2012
// Leandro Munoz 2020 leacolumbi@gmail.com
// MIT license

#include <Arduino.h>


template <typename T> unsigned int serial_writeAnything (const T& value)
  {
    const byte * p = (const byte*) &value;
    unsigned int i;
    byte temp [sizeof value];
    for (i = 0; i < sizeof value; i++){
      temp[i] = *p++;
    }
    Serial.write(temp, sizeof value);
    //Serial.println(String(temp[0]) + " zero " + String(temp[1]) + "one" + String(temp[2]) + "two" + temp[3] + "three");
    return sizeof (value);
  }  // end of serial_writeAnything

template <typename T> unsigned int serial_readAnything (const T& value)
  {
    byte * p = (byte*) &value;
    unsigned int i;
    byte temp [sizeof value];
    Serial.readBytes(temp, sizeof value);
    for (i = 0; i < sizeof value; i++){
      *p++ = temp[i];
    }
    return i;
  }  // end of serial_readAnything
