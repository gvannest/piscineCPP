#include "Brain.hpp"
#include <iostream>
#include <string>
#include <sstream>


Brain::Brain(void){}

Brain::~Brain(void){}

std::string const    Brain::identify(void) const {
    std::ostringstream addrSS;
    addrSS << std::hex << this;
    return addrSS.str();
}