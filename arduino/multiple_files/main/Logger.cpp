#include "Logger.h"

// constructor
Logger::Logger(int logType)
{
  setLogType(logType);
}

void Logger::setLogType(int _logType)
{
    logType = _logType;
}
