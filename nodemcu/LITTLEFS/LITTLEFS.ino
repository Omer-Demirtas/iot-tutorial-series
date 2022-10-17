#include "LittleFS.h";
#include "FileService.h";

FileService service = FileService();

void dataCome(String d) { Serial.println(d);}

void readFile(void (*dc)(String))
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
    
    dc(data);
    Serial.println(data);
    file.close();
  }
}

void updateFile()
{
  File f = LittleFS.open("/config.txt", "a");
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
  readFile(dataCome);
  delay(5000);
}
