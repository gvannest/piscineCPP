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

ScavTrap::ScavTrap(std::string name) :  _hitPoints(100),
                                        _maxHitPoints(100),
                                        _energyPoints(50),
                                        _maxEnergyPoints(50),
                                        _level(1),
                                        _name(name),
                                        _meleeAttackDamage(20),
                                        _rangedAttackDamage(15),
                                        _armorDamageReduction(3)
{
    std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap destructor called. " << this->_name << " has died." << std::endl;
}

void        ScavTrap::rangedAttack(std::string const & target) const{
        std::cout << "SC4V-TP " << this->_name << " launched a ranged attack, on " << 
            target << " causing " <<
            this->_rangedAttackDamage << " points in damages!" << std::endl;
}

void        ScavTrap::meleeAttack(std::string const & target) const{
    std::cout << "SC4V-TP " << this->_name << " launched a melee attack, on " << 
            target << " causing " <<
            this->_meleeAttackDamage << " points in damages!" << std::endl;
}

void        ScavTrap::challengeNewcomer(std::string const & target){
    int idx = rand() % 5;
    std::string challenge = ScavTrap::_randChallenges[idx];
    std::cout << "SC4V-TP " << this->_name << " challenges " << target << 
                " on " << challenge << std::endl;
    this->_energyPoints -= 25;
}

void        ScavTrap::takeDamage(unsigned int amount){
    int oldHp = this->_hitPoints;
    this->_hitPoints -= (amount - this->_armorDamageReduction);
    if (this->_hitPoints <= 0)
        this->_hitPoints = 0;
    std::cout << "SC4V-TP " << this->_name << " has taken a hit with " <<
                oldHp - this->_hitPoints << " points in damages!" << std::endl;
}

void        ScavTrap::beRepaired(unsigned int amount){
    int         oldHp = this->_hitPoints;
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    
    std::cout << "SC4V-TP " << this->_name << " is getting cured, recovering " <<
                this->_hitPoints - oldHp << " energy points!" << std::endl;
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

int                 ScavTrap::getHitPoints(void) const{
    return this->_hitPoints;
}

int                 ScavTrap::getMaxHitPoints(void) const{
    return this->_maxHitPoints;
}

int                 ScavTrap::getEnergyPoints(void) const{
    return this->_energyPoints;
}

int                 ScavTrap::getMaxEnergyPoints(void) const{
    return this->_maxEnergyPoints;
};

unsigned int        ScavTrap::getLevel(void) const{
    return this->_level;
}

std::string         ScavTrap::getName(void) const{
    return this->_name;
}

unsigned int        ScavTrap::getMeleeDamage(void) const{
    return this->_meleeAttackDamage;
}

unsigned int        ScavTrap::getRangedDamage(void) const{
    return this->_rangedAttackDamage;
}

unsigned int        ScavTrap::getArmorReduction(void) const{
    return this->_armorDamageReduction;
}
