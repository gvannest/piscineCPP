#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) :
    AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const & instance) : AWeapon(instance) {
}

PowerFist::~PowerFist(void){}

PowerFist &   PowerFist::operator=(PowerFist const & rhs){
    this->AWeapon::operator=(rhs);
    return *this;
}

void    PowerFist::attack(void) {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

