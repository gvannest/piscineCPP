#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>

class Logger {

    private:
        std::string const   _filename;
        void                logToConsole(std::string const &str) const;
        void                logToFile(std::string const &str) const;
        std::string         makeLogEntry(std::string const & msg) const;

    public:
        Logger(std::string const & file);
        ~Logger(void);

        void    log(std::string const & dest, std::string const & message);


};

#endif