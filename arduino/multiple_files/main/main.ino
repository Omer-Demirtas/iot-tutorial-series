#include "util_functions.h";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(calculate(3));
  delay(4000);
}
