#include "../include/Config.h"

namespace loggingConfig
{
    std::string loggingDir = "./logs/";

    std::string baseFileName = "applicationLog";

    bool useConsoleOutput = true;

    bool useFileOutput = true;

    int maxFileSizeMB = 5;

    int maxBackupFiles = 0;

    loggingConfig::LogLevel logLevel = loggingConfig::Info;

}