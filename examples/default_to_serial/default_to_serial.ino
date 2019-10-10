/**
* This sketch demonstrates using the ArduinoPrintf library with the default setup,
* which requires no initialization. The Serial class will be used as the output
* for the ArduinoPrintf library.
*
* You are still responsible for initializing the Print class in setup(), the
* ArduinoPrintf library will not do that for you.
*/

#include <LibPrintf.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  printf("I'm alive!\n");
  delay(1000);
}
