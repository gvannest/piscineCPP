#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"


Peon::Peon(std::string name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & instance) : Victim(instance){
}

Peon::~Peon (void) {
    std::cout << "Bleuark..." << std::endl;
}

void            Peon::getPolymorphed(void) const{
    std::cout << this->getName() << " was just polymorphed into a pink poney!" << std::endl;
}

Peon &  Peon::operator=(Peon const & rhs){
    this->Victim::operator=(rhs);
    return *this;
}



