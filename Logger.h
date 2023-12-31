#ifndef Logger_H
#define Logger_H

#include "Arduino.h"
class Logger
{
  public:
    enum LogLevel {Debug, Info, Warning, Severe};
    struct LogConfig
    {
      bool debug = false;
      bool info = false;
      bool warning = true;
      bool severe = true;
    };
  
    Logger(LogConfig conf);
    Logger();

    static LogConfig generateConf(bool debug, bool info, bool warning, bool severe);
    void setConf(LogConfig conf);
	LogConfig getConf();

    void printline(const char* in);
    void printline(const char* in, const char* level);
    void printline(const char* in, LogLevel level);

    
  private:
    LogConfig loggerConf;
};

#endif
