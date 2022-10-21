#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "FileServicce.h";

String ssid = "NAME";
String password = "PASSWORD";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("connected..! ");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handleOnConnect);
  server.onNotFound(handleNotFound);

  server.begin();
  
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handleOnConnect() {
  server.send(200, "text/html", "Hello"); 
}

void handleNotFound(){
  server.send(404, "text/plain", "Not found");
}
 
