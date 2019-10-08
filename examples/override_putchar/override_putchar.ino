#include <ArduinoPrintf.h>

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
