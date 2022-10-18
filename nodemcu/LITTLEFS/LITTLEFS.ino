#include "LittleFS.h";

void dataCome(String d) { Serial.println(d);}
String configDecode(String conf) { return "asd"; }

String reaLineByLine(String (*dc)(String))
{
  File file = LittleFS.open("/config.txt", "r");
  if(!file){
    Serial.println("Failed to open file for reading");
  }
  else
  {
    String result = "";
    while(file.available()){
      String s = file.readString();
      int index = s.indexOf(":");
      String key = s.substring(0, index);
      String value = s.substring(index + 1, s.length());  
      //String value = s.substring(0, s.find(delimiter));
      Serial.println(s);
      Serial.println(key);
      Serial.println(value);
      Serial.println("******");
    }
    file.close();
    return result;
  }
  return "";
}

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
  String a = reaLineByLine(configDecode);
  delay(10000);
}
