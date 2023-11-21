#include "Arduino.h"
#include "Logger.h"

Logger::Logger(LogConfig conf)
{
  loggerConf = conf;
  Serial.println("Logger: Serial Test");
}
Logger::Logger()
{
  loggerConf = generateConf(true, true, true, true);
}
Logger::LogConfig Logger::generateConf(bool debug, bool info, bool warning, bool severe)
{
  LogConfig out;
  out.debug = debug;
  out.info = info;
  out.warning = warning;
  out.severe = severe;
  return out;
}
void Logger::setConf(LogConfig conf)
{
  loggerConf = conf;
}
Logger::LogConfig Logger::getConf(){
	return loggerConf;
}

void Logger::printline(const char* in)
{
  printline(in, LogLevel::Info);
}
void Logger::printline(const char* in, const char* level)
{
  if (strcmp(level, "debug") == 0)
  {
    printline(in, Debug);
  }
  if (strcmp(level, "info") == 0)
  {
    printline(in, Info);
  }
  if (strcmp(level, "warning") == 0)
  {
    printline(in, Warning);
  }
  if (strcmp(level, "severe") == 0)
  {
    printline(in, Severe);
  }
}

void Logger::printline(const char* in, LogLevel level)
{
  switch (level)
  {
  case Debug:
    if (loggerConf.debug)
    {
      Serial.print("Debug: ");
      Serial.println(in);
    }
    break;
  case Info:
    if (loggerConf.info)
    {
      Serial.print("Info: ");
      Serial.println(in);
    }
    break;
  case Warning:
    if (loggerConf.warning)
    {
      Serial.print("WARNING: ");
      Serial.println(in);
    }
    break;
  case Severe:
    if (loggerConf.severe)
    {
      Serial.print("SEVERE: ");
      Serial.println(in);
    }
    break;
  }
}
