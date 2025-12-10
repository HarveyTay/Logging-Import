#include <string>

namespace Integrity
{

    int startChain();

    std::string hashFunction(std::string& plainData);

    std::string hashVerification(std::string path);

    std::string appendEntry(std::string logData,
                            std::string currenthash,
                            std::string previousHash,
                            std::string utcTimestamp,
                            std::string localTimestamp);

    std::string getLocalTime();
    std::string getUTCTime();

    struct logStructure
    {
        std::string localTime;
        std::string utcTime;

        std::string logData;
        
        std::string currentHash;
        std::string previousHash;
    };
    
}