//
// Created by mikag on 12/22/2018.
//

#ifndef ARPG_UTIL_H
#define ARPG_UTIL_H


#include <string>
#include <Configuration/DebugLevel.h>

class Util
{
public:
    /// Exit with an error condition.
    static void ErrorExit();
    /// Exit with a success condition.
    static void SuccessExit();

    /// Log something to the console (mirrored to engine log). Only runs when DEBUG_LOG enabled.
    /// \param log - The string to log
    static void Log(std::string log);

    /// Log a warning to the console (mirrored to engine log). Only runs when DEBUG_LOG enabled.
    /// \param log - The string to log
    static void LogWarning(std::string log);

    /// Log an error to the console (mirrored to engine log). Only runs when DEBUG_LOG enabled.
    /// \param log - The string to log
    static void LogError(std::string log);

    ///Empty the log file.
    static void CleanLogFile();

private:
    static std::ofstream log_ofs;
};


#endif //ARPG_UTIL_H
