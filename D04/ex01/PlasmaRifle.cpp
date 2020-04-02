#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle(void) :
    AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & instance) : AWeapon(instance) {
}

PlasmaRifle::~PlasmaRifle(void){}

PlasmaRifle &   PlasmaRifle::operator=(PlasmaRifle const & rhs){
    this->AWeapon::operator=(rhs);
    return *this;
}

void    PlasmaRifle::attack(void) {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

