#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
  private:
    int logType;
  
  public:
    Logger(int logType);
    void log(char* log);

    void setLogType(int logType);
    int getLogType() { return logType; }
};

#endif
