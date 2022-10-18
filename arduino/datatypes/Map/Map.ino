#include "Map.hpp";

Map<int> m;
void setup() {
   Serial.begin(9600);
}

void loop() {

  m.append("12", 12); 
  delay(1000);
}
