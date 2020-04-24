#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

std::string const     FragTrap::_randAttacks[5] = {
    "Toad Throwing",
    "Sword",
    "Acid",
    "Bow",
    "Developer",
};

FragTrap::FragTrap(std::string name)
: ClapTrap(100, 100, 30, 20, 5, name, "I WILL FRAG YOU B****!!") {
    std::cout << "FragTrap default constructor called for " << this->getName() << std::endl;
}

FragTrap::FragTrap(FragTrap const & instance){
    std::cout << "FragTrap copy constructor called for " << this->getName() << std::endl;
    *this = instance;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap destructor called. " << this->getName() << " has died." << std::endl;
}

void        FragTrap::vaulthunter_dot_exe(std::string const & target){
    if (this->getEnergyPoints() - 25 < 0)
        std::cout << this->getName() << " does not have enough energy points to " <<
        "launch this attack (25 needed)." << std::endl;
    else {
        int idx = rand() % 5;
        std::string attack = FragTrap::_randAttacks[idx];
        std::cout << "FR4G-TP " << this->getName() << " launched a " << attack << " attack on" <<
                    target << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 25);
    }
}

FragTrap &  FragTrap::operator=(FragTrap const & rhs){
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

