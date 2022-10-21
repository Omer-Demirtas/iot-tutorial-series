#include "Map.hpp";

Map<String, int> m(10);

int i = 0;
void setup() {
   Serial.begin(115200);
   for(int k = 0; k < 6; k++)
   {
    m.append(String(k), k); 
   }
}

void loop() {
  //m.getKeys();
 
  m.print();
  
  delay(5000);
}
