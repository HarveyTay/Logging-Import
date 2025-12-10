#include "../include/Integrity.h"
#include "../include/picosha2.h"

#include <chrono>
#include <sstream>
#include <format>

namespace Integrity
{
    int startChain(){
        return 0;
    }

    std::string hashFunction(std::string& plainData){
        return picosha2::hash256_hex_string(plainData);
    }

    std::string hashVerification(std::string path){

    }

    std::string appendEntry(std::string logData,
                            std::string currenthash,
                            std::string previousHash,
                            std::string utcTimestamp,
                            std::string localTimestamp){

        std::string readyString;

        std::string start = "---START---\n";
        std::string end = "---END---\n";

        readyString =   start +
                        "Local Time: "+ localTimestamp + "\n" +
                        "UTC Time: "+ utcTimestamp + "\n" +
                        "Previous Hash: "+ previousHash + "\n" +
                        "Current Hash: "+ currenthash + "\n" +
                        "Log: "+ logData + "\n" +
                        end + "\n";
        
        return readyString;
    }

    std::string getLocalTime(){
        auto utcTime = std::chrono::system_clock::now();

        auto time = std::chrono::current_zone()->to_local(utcTime);

        std::string localTime = std::format("{:%F %T}", time);

        return localTime;
    }

    std::string getUTCTime(){
        auto rawUTCTime = std::chrono::system_clock::now();

        std::string formattedUTCTime = std::format("{:%F %T}", rawUTCTime);

        return formattedUTCTime;
    }
    
}