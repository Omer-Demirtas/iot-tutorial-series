#ifndef UTILS_H
#define UTILS_H
#include <Arduino.h>

class Utils
{
  public:
    Utils();
    void log();
    String readFile(String path);
    String *readJson(String path, String *fields, int size);
};

#endif
