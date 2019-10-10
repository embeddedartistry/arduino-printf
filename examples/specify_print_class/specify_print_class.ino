/**
* This sketch demonstrates using the ArduinoPrintf library with a custom
* Print class of your choice. Call printf_init() with the desired output class.
* Any class which has Print as a base class can be used.
*
* You are still responsible for initializing the Print class in setup(), the
* ArduinoPrintf library will not do that for you.
*/

#include <LibPrintf.h>

void setup() {
  // Specify the print class to use with printf().
  // Any class derived from Print will work.
  printf_init(Serial1);

  // But the important detail: you are responsible for initializing the interface!
  Serial1.begin(115200);
}

void loop() {
  printf("I'm alive!\n");
  delay(1000);
}
