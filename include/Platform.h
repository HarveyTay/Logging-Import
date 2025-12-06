#pragma once
#include <string>
#include <cstdint>

namespace harvey::Platform {

    bool isWindows();
    bool isLinux();
    bool isMac();

    std::uint32_t getProcessID();
    std::uint64_t getThreadID();

    std::string getExecutablePath();
    std::string getExecutableName();

    bool createDirectory(const std::string& path);
    bool fileExists(const std::string& path);

    bool setFilePermissionsOwnerOnly(const std::string& path);
}