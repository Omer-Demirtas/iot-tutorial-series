#include "util_functions.h";
#include "Logger.h";

Logger logger = Logger(13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(calculate(3));
  Serial.println(logger.getLogType());
  delay(4000);
}
