#include "Logger.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Logger::Logger(std::string const & file) : _filename(file){}

Logger::~Logger(void){}

void    Logger::logToConsole(std::string const &str) const{
    std::cout << str << std::endl;
}

void    Logger::logToFile(std::string const &str) const{
    std::ofstream ofs(this->_filename, std::ofstream::app);
    ofs << str << std::endl;
}

std::string     Logger::makeLogEntry(std::string const & msg) const{
    std::ostringstream  output;
    std::time_t rawtime = std::time(0); // get current time and store it in rawtime
    std::tm     *timeInfo = std::localtime(&rawtime); // create a structure which parses the time so that we can exract it in human readable form
                                                    // either through now->tm_year... or via methods such as asctime.
    std::string time_str = asctime(timeInfo);
    time_str.pop_back();
    output << time_str << " - " <<  msg;
    return output.str();
}

void    Logger::log(std::string const & dest, std::string const & message){
    std::string dst[2] = {"console", "file"};

    typedef    void (Logger::*logFunc)(std::string const &) const;
    logFunc     logDst[2] = {&Logger::logToConsole, &Logger::logToFile};

    for (int i = 0; i < 2; i++){
        if (dst[i] == dest)
            (this->*logDst[i])(this->makeLogEntry(message));
    } 
}

