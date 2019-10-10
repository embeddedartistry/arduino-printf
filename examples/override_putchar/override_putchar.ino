/**
* This sketch demonstrates the ability to override the ArduinoPrintf library's
* default implementation of _putchar() with a custom user implementation.
* You can do anything you want in your _putchar() function: output to multiple ports,
* filter data, add extra characters, etc.
*/

#include <LibPrintf.h>

void setup() {
  // But the important detail: you are responsible for initializing the interface!
  Serial.begin(115200);
}

void _putchar(char character)
{
  Serial.print(character);
  Serial.print(' ');
}

void loop() {
  printf("I'm alive!\n");
  delay(1000);
}
