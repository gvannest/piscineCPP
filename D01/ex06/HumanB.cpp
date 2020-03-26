#include <iostream>

#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string const name, Weapon * weapon) : _name(name), _weapon(weapon){}

HumanB::~HumanB(void){}

void        HumanB::setWeapon(Weapon & weapon){
    this->_weapon = &weapon;
}

void        HumanB::attack(void) const{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}