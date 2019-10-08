#include <ArduinoPrintf.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  printf("I'm alive!\n");
  delay(1000);
}
