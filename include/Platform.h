#pragma once
#include <string>

namespace OSUtilities {
    bool isWindows();
    bool isLinux();
    bool isMac();

    int getProcessID();
    int getThreadID();

    std::string getExecutableName();
    std::string getExecutablePath();
}