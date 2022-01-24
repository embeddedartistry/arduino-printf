/**
* This sketch demonstrates the ability to override the ArduinoPrintf library's
* default implementation of putchar_() with a custom user implementation.
* You can do anything you want in your putchar_() function: output to multiple ports,
* filter data, add extra characters, etc.
*/

#include <LibPrintf.h>

void setup() {
  // But the important detail: you are responsible for initializing the interface!
  Serial.begin(115200);
}

void putchar_(char character)
{
  Serial.print(character);
  Serial.print(' ');
}

void loop() {
  printf("I'm alive!\n");
  delay(1000);
}
