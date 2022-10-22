#include "Utils.hpp";
#include "Arduino.h";
#include "LittleFS.h";
#include <ArduinoJson.h>

Utils::Utils()
{ }

void Utils::log()
{
  Serial.println("asd");
}
String Utils::readFile(String path)
{
  File file = LittleFS.open(path, "r");
  String data = ""; 

  if(!file){
    Serial.println("Failed to open file for reading");
  }
  else
  {
    while(file.available()){
      data += file.readString();
    }
    file.close();

    return data;
  }
  return data;
}

String *Utils::readJson(String path, String *fields, int size)
{
  StaticJsonDocument<200> doc;
  
  String json = readFile(path);
  
  DeserializationError error = deserializeJson(doc, json);

  String* jsons = new String[size];

  for (int i = 0; i < size; i++)
  {
    Serial.print(fields[i]);
    
    String s = doc[fields[i]];
    Serial.println(s);

    jsons[i] = s;
  }
  
  return jsons;
}
