#include <iostream>

#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string const name, Weapon & weapon) : _name(name), _weapon(weapon){}

HumanA::~HumanA(void){}

void        HumanA::setWeapon(Weapon & weapon){
    this->_weapon = weapon;
}

void        HumanA::attack(void) const{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}