#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "NAME";
const char* password = "PASSWORD";

WiFiClient wifiClient;

String post()
{
  HTTPClient http;

  if (WiFi.status() == WL_CONNECTED) 
  {
    String path = "https://jsonplaceholder.typicode.com/posts";   
    StaticJsonDocument<2048> doc;

    doc["title"] = "TITLE";
    doc["body"] = "BODY";
    doc["userId"] = 1;
    
    String data;

    serializeJson(doc, data);

    http.begin(wifiClient, path.c_str());
    http.addHeader("Content-Type", "application/json;");
   
    int httpCode = http.POST(data);
  
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
  String result = post();

  Serial.println(result);
}

void loop() {  }