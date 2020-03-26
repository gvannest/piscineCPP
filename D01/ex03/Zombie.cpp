#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _type("standard"){
    std::cout << "A new Zombie has joined the Horde!!" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Zombie " << this->_name << " has died" << std::endl;
}

void    Zombie::advert(void) const{
    std::cout << '<' << this->_name << " (" << this->_type << ")> Hello my friend!..." << std::endl;
}

void    Zombie::set_name(std::string const & name){
    this->_name = name;
}

