#pragma once
#include <string> 

namespace harvey::loggingConfig
{
    std::string loggingDir; //location of output
    std::string baseFileName; //base name of log files

    bool useConsoleOutput; //use console to log
    bool useFileOutput; //use file to log

    int maxFileSizeMB; //max size of log file in MB
    int maxBackupFiles; //max number of backup log files

    enum LogLevel //logging level
    {
        Trace = 0,
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    } logLevel;
};
