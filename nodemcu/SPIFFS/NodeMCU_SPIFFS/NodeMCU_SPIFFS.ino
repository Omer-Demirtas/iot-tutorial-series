#include<ESP8266WiFi.h>
#include<FS.h>

void setup()
{
delay(1000);
Serial.begin(115200);
Serial.println();
//Initialize File system
if(SPIFFS.begin())
{
Serial.println("SPIFFS got Initialized successfully");
}
else
{
Serial.println("SPIFFS Initialization is failed");
}
//Format File system
if(SPIFFS.format())
{
Serial.println("File system Formatted");
}
else
{
Serial.println("File system formatting error");
}
//create a new file and write data to the file
File f=SPIFFS.open(filename,"w");
if(!f)
{
Serial.println("file open failed");
}
else
{
//Write data to file
Serial.println("writing Data to File");
f.print("hello world,welcome to IOT Platform");
f.close();
}
}
void loop() {
int i;
//Read File Data
File f=SPIFFS.open(filename,"r");
if(!f)
{
Serial.println("file open failed");
}
else
{
Serial.println("Reading Data from file");
//data from file
//read upto last character
for(i=0;i<f.size();i++)
{
Serial.print((char)f.read());
}
//close file
f.close();
Serial.println("file Closed");
}
delay(5000);
}
