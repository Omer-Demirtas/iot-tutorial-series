#include "LittleFS.h"
 
void setup() {
  Serial.begin(115200);
  Serial.println("Hellow World"); 
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
}
 
void loop() {
  Serial.println("Hello");
  File file = LittleFS.open("/config.txt", "r");
  if(!file){
    Serial.println("Failed to open file for reading");
  }
  else
  {
    Serial.println("File Content:");
    while(file.available()){
      Serial.write(file.read());
    }
    file.close();
  }
  
  delay(3000); 

  
}
