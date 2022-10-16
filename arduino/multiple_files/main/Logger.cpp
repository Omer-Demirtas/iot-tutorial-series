#include "Logger.h";
#include "Arduino.h";

// constructor
Logger::Logger(int type)
{
  Serial.print("type : ");
  Serial.print(type);
  Serial.println();
  setLogType(type);
}

void Logger::setLogType(int type)
{
  logType = type;
}
