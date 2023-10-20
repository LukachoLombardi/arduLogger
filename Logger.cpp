#include "Arduino.h"
#include "Logger.h"

Logger::Logger(LogConfig conf)
{
  loggerConf = conf;
}
Logger::Logger()
{
  loggerConf = generateConf(true, true, true, true);
}
void Logger::init(Stream *inStream)
{
  stream = inStream;
  stream->println("Serial Initialized");
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
      stream->print("Debug: ");
      stream->println(in);
    }
    break;
  case Info:
    if (loggerConf.info)
    {
      stream->print("Info: ");
      stream->println(in);
    }
    break;
  case Warning:
    if (loggerConf.warning)
    {
      stream->print("WARNING: ");
      stream->println(in);
    }
    break;
  case Severe:
    if (loggerConf.severe)
    {
      stream->print("SEVERE: ");
      stream->println(in);
    }
    break;
  }
}
