#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "NAME";
const char* password = "PASSWORD";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("connected..! ");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
 
String SendHTML(){  
  String ptr = "<!DOCTYPE html>\n";
  ptr +="<html>\n";
  ptr +="<head>\n";
  ptr +="<title>NodeMCU</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Hello World</h1>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
