#include "Map.hpp";

Map<String, int> m(10);

int i = 0;
void setup() {
   Serial.begin(9600);
   for(int k = 0; k < 6; k++)
   {
    m.append(String(k), k); 
   }
}

void loop() {
  Serial.println(i++);
  Serial.println(m.get(String(i)));
  Serial.println(m.getSize());
  delay(2000);
}
