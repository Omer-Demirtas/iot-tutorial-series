#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
  private:
    int logType = 0;
  
  public:
    Logger(int type);
    void log(char* log);

    void setLogType(int type);
    int getLogType() { return logType; }
};

#endif
