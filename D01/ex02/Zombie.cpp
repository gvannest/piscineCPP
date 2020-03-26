#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string const name, std::string const type) : _name(name), _type(type){
    std::cout << "Zombie " << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Zombie " << this->_name << " has died" << std::endl;
}

void    Zombie::advert(void) const{
    std::cout << '<' << this->_name << " (" << this->_type << ")> Hello my friend!..." << std::endl;
}


