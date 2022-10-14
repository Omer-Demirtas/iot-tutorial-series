#include<ESP8266WiFi.h>
#include<FS.h>
bool FS_AVALIABLE = false;


void initFileSystem()
{
 if(SPIFFS.begin()){
  FS_AVALIABLE = true;
  Serial.println("file true");
 }
 else {
  FS_AVALIABLE = false;
  Serial.println("file folse");
 }
}
void readFile(String filename){
    Serial.println("Init file");

  File f=SPIFFS.open(filename,"r");
  if(!f)
  {
    Serial.println("file open failed");
  }
  else
  {
    Serial.println("Reading Data from file");
    int i = 0;
    for(i=0;i<f.size();i++)
    {
      Serial.print((char)f.read());
    }
    f.close();
  }
}

void write(){}
void create(){}

void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println("Start Working");
  initFileSystem();
  if(SPIFFS.format())
{
Serial.println("File system Formatted");
}
else
{
Serial.println("File system formatting error");
}
  readFile("/data.txt");
}
void loop() {
  readFile("/data.txt");
  delay(1000);
}
