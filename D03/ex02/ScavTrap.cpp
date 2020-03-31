#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

std::string const     ScavTrap::_randChallenges[5] = {
    "Interplanetary Ninja Chatterbox",
    "Unlock Heads",
    "Death From Above",
    "Cleaniness Uprising",
    "The Voyage of Captain Chef",
};

ScavTrap::ScavTrap(std::string name, int ep, int maxEp, unsigned int mA,
                unsigned int rA, unsigned int aDR) : ClapTrap(ep, maxEp, mA, rA, aDR, name) {
    std::cout << "ScavTrap default constructor called for " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & instance){
    std::cout << "ScavTrap copy constructor called for " << this->getName() << std::endl;
    *this = instance;
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap destructor called. " << this->getName() << " has died." << std::endl;
}

void        ScavTrap::challengeNewcomer(std::string const & target){
    int idx = rand() % 5;
    std::string challenge = ScavTrap::_randChallenges[idx];
    std::cout << "SC4V-TP " << this->getName() << " challenges " << target << 
                " on " << challenge << std::endl;
}

ScavTrap &  ScavTrap::operator=(ScavTrap const & rhs){
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