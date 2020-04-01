#include <iostream>
#include "Victim.hpp"


Victim::Victim(void) {}

Victim::Victim(std::string name) : _name(name) {
    std::cout << "A random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const & instance){
    *this = instance;
}

Victim::~Victim (void) {
    std::cout << "Victim "<< this->_name << " died for no apparent reasons!" << std::endl;
}

Victim &      Victim::operator=(Victim const & rhs){
    this->_name = rhs.getName();
    return *this;
}

std::string     Victim::getName(void) const{
    return this->_name;
}

void            Victim::getPolymorphed(void) const{
    std::cout << this->_name << " was just polymorphed in a cute little sheep!" << std::endl;
}


std::ostream &      operator<<(std::ostream & o, Victim const & rhs){
    o << "Je suis " << rhs.getName() << " and i like otters!" << std::endl;
    return o;
}




