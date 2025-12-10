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

            //if no / return 
            return (pos == std::string::npos) ? fullPath : fullPath.substr(pos + 1);
        } else if (isLinux())
        {
            //erm not sure?
        } else if (isMac())
        {
            //erm not sure either?
        }
    }

    bool createDirectory(const char* path) {
        if (isWindows())
        {
            CreateDirectoryA(path/*,maybe add file permissions here?*/);
        } else if (isLinux())
        {
            mkdir(path, /*can also set perms here maybe?*/)
        }else if (isMac())
        {
            mkdir(path, /*same as b4*/)
        }
    }

    std::string fileExists(const std::string& path) {
        if (isWindows())
        {
            if  (fopen_s(NULL, path.c_str(), "r") == 0) {
                return path;
            } else {
                return NULL;
            }
        } else if (isLinux() || isMac())
        {
            if (FILE* file = fopen(path.c_str(), "r")) {
                fclose(file);
                return path;
            } else {
                return NULL;
            }
        }
    }

    bool setFilePermissionsOwnerOnly(const std::string& path) {
        if (isWindows())
        {
            // windows is complicated need more research or set at create
            return false; // Not implemented
        } else if (isLinux() || isMac())
        {
            if (chmod(path.c_str(), S_IRUSR | S_IWUSR) == 0) {
                return true;
            } else {
                return false;
            }
        }
    }

}
