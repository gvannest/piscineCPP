#include "SuperTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 60, 20, 5, name), FragTrap(name), NinjaTrap(name) {
    std::cout << "SuperTrap default constructor called for " << this->getName() << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & instance){
    std::cout << "SuperTrap copy constructor called for " << this->getName() << std::endl;
    *this = instance;
}

SuperTrap::~SuperTrap(void){
    std::cout << "SuperTrap destructor called. " << this->getName() << " has died." << std::endl;
}

SuperTrap &  SuperTrap::operator=(SuperTrap const & rhs){
    if (this == &rhs)
        return *this;
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_name = rhs.getName();
    this->_meleeAttackDamage = rhs.getMeleeDamage();
    this->_rangedAttackDamage = rhs.getRangedDamage();
    this->_armorDamageReduction = rhs.getArmorReduction();
    return *this;
}

