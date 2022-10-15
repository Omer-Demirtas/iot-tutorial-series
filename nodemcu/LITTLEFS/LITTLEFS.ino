#include "LittleFS.h";

void readFile()
{
  File file = LittleFS.open("/config1.txt", "r");
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

void updateFile()
{
  File f = LittleFS.open("/config1.txt", "a");
  if(!f){
    Serial.println("Failed to open file for reading");
  }
  else
  {
    if(f.println("APPENDED FILE LINE")){
      Serial.println("File content was appended");
    } else {
      Serial.println("File append failed");
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  
}
 
void loop() {
  Serial.println("-------------------------------");
  readFile();
  delay(5000);
  updateFile();
}
