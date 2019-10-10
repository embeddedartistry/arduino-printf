#include <ArduinoPrintf.h>

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
