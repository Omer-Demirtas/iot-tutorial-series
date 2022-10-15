#include "LittleFS.h";

void readFile()
{
  File file = LittleFS.open("/config.txt", "r");
  if(!file){
    Serial.println("Failed to open file for reading");
  }
  else
  {
    String data = "";
    while(file.available()){
      data += file.readString();
    }
    
    Serial.println(data);
    file.close();
  }
}


void setup() {
  Serial.begin(115200);
  Serial.println("Hellow World"); 
  
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

}
 
void loop() {
  readFile();
  delay(5000);
}
