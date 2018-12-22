//
// Created by mikag on 12/22/2018.
//

#include <fstream>
#include <iostream>
#include "Util.h"

std::ofstream Util::log_ofs;

void Util::ErrorExit()
{
    int c;
    printf("Engine exited in an errored state. Press ENTER to continue...");
    fflush(stdout);
    do c = getchar(); while((c != '\n') && (c != EOF));
    exit(1);
}

void Util::SuccessExit()
{
    int c;
    printf("Engine shutdown complete. Press ENTER to continue...");
    fflush(stdout);
    do c = getchar(); while((c != '\n') && (c != EOF));
    exit(0);
}

void Util::Log(std::string log)
{
#if defined DEBUG_ALL || defined DEBUG_LOG
    if(!log_ofs.is_open())
        log_ofs.open("engine_log.txt", std::ofstream::out | std::ofstream::app);
    std::cout << "(LOG) " << log << std::endl;
    log_ofs << "(LOG) " << log << std::endl;
#endif
}

void Util::CleanLogFile()
{
    if(log_ofs.is_open())
        log_ofs.close();
    log_ofs.open("engine_log.txt", std::ofstream::out | std::ofstream::trunc);
}

void Util::LogWarning(std::string log)
{
#if defined DEBUG_ALL || defined DEBUG_WRN
    if(!log_ofs.is_open())
        log_ofs.open("engine_log.txt", std::ofstream::out | std::ofstream::app);
    std::cout << "(WRN) " << log << std::endl;
    log_ofs << "(WRN) " << log << std::endl;
#endif
}

void Util::LogError(std::string log)
{
#if defined DEBUG_ALL || defined DEBUG_ERR
    if(!log_ofs.is_open())
        log_ofs.open("engine_log.txt", std::ofstream::out | std::ofstream::app);
    std::cout << "(ERR) " << log << std::endl;
    log_ofs << "(ERR) " << log << std::endl;
#endif
}
