#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "NAME";
const char* password = "PASSWORD";

WiFiClient wifiClient;

String get()
{
  HTTPClient http;

  if (WiFi.status() == WL_CONNECTED) 
  {
    String path = "http://jsonplaceholder.typicode.com/users/1";   
  
    http.begin(wifiClient, path.c_str());

    int httpCode = http.GET();
  
    String payload = http.getString();
  
    http.end();

    return payload;
  }
  return "";
}

void setup() 
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.print("Connected ");
  Serial.println(WiFi.localIP());

  // Send Request
  String result = get();

  Serial.println(result);
}

void loop() {  }