#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string const name, int const age) : _name(name), _age(age){
    std::cout << "Pony " << this->_name << " is born." << std::endl;
}

Pony::~Pony(void){
    std::cout << "Pony " << this->_name << " has died." << std::endl;
}

std::string     Pony::get_name(void) const{
    return this->_name;
}

int             Pony::get_age(void) const{
    return this->_age;
}

std::string     Pony::make_sound(void){
    return Pony::_sound
;}

std::string const   Pony::_sound = "meuh";