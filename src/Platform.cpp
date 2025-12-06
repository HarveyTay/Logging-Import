#include "../include/Platform.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <processthreadsapi.h>
#elif defined(__linux__)
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <pthread.h>
#elif defined(__APPLE__)
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <pthread.h>
#endif

namespace platform {

    // -----------------------------------
    // OS Detection
    // -----------------------------------
    bool isWindows() {
        #ifdef _WIN32
            return true;
        #endif
    }

    bool isLinux() {
        #ifdef __linux__
            return true;
        #endif
    }

    bool isMac() {
        #ifdef __APPLE__
            return true;
        #endif
    }

    // get PID
    std::uint32_t getProcessID() {
        if (isWindows()) 
        {
            return std::uint32_t(GetCurrentProcessId());
        } else if (isLinux() || isMac()) 
        {
            return std::uint32_t(getpid());
        }
    }

    // get TID
    std::uint64_t getThreadID() {
        if (isWindows())
        {
            return std::uint64_t(GetCurrentThreadId());
        } else if (isLinux() || isMac())
        {
            return std::uint64_t(pthread_self());
        }
    }

    std::string getExecutableName() {
        if (isWindows())
        {
            char store[MAX_PATH];
            GetModuleFileNameA(NULL, store, MAX_PATH);

            std::string fullPath(store);
            auto pos = fullPath.find_last_of("\\/");

        }
        
    }

    bool createDirectory(const std::string& path) {
        // mkdir() compatible with both?
    }

    bool fileExists(const std::string& path) {
        // stat() and GetFileAttributes()
    }

    bool setFilePermissionsOwnerOnly(const std::string& path) {
        // chmod() more research for windows
    }

}
