#include "Utils.hpp";
#include "LittleFS.h";
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
Utils utils;

void handleNotFound(){ server.send(404, "text/plain", "Not found"); }
void handleHomePage(){ server.send(200, "text/html", utils.readFile("/pages/index.html")); }
void handleHomePageStyle(){ server.send(200, "text/css", utils.readFile("/pages/style.css")); }
void handleHomePageJs(){ server.send(200, "text/javascript", utils.readFile("/pages/app.js")); }

void setup() 
{
  Serial.begin(115200);

  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  String filters[] = {"wifiName", "password"};
  String *configs = utils.readJson("/config.json", filters, 2);

  WiFi.begin(configs[0], configs[1]);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("connected..! ");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handleHomePage);
    server.on("/style.css", handleHomePageStyle);
  server.on("/app.js", handleHomePageJs);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  //Serial.println(utils.readFile("/config.json"));
  delay(4000);
}
