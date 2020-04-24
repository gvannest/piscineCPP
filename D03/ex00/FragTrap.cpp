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

FragTrap::FragTrap(std::string name) :  _hitPoints(100),
                                        _maxHitPoints(100),
                                        _energyPoints(100),
                                        _maxEnergyPoints(100),
                                        _level(1),
                                        _name(name),
                                        _meleeAttackDamage(30),
                                        _rangedAttackDamage(20),
                                        _armorDamageReduction(5)
{
    std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap destructor called. " << this->_name << " has died." << std::endl;
}

void        FragTrap::rangedAttack(std::string const & target) const{
        std::cout << "FR4G-TP " << this->_name << " launched a ranged attack, on " << 
            target << " causing " <<
            this->_rangedAttackDamage << " points in damages!" << std::endl;
}

void        FragTrap::meleeAttack(std::string const & target) const{
    std::cout << "FR4G-TP " << this->_name << " launched a melee attack, on " << 
            target << " causing " <<
            this->_meleeAttackDamage << " points in damages!" << std::endl;
}

void        FragTrap::vaulthunter_dot_exe(std::string const & target){
    if (this->_energyPoints - 25 < 0)
        std::cout << this->_name << " does not have enough energy points to " <<
        "launch this attack (25 needed)." << std::endl;
    else {
        int idx = rand() % 5;
        std::string attack = FragTrap::_randAttacks[idx];
        std::cout << "FR4G-TP " << this->_name << " launched a " << attack << " attack on" <<
                    target << std::endl;
        this->_energyPoints -= 25;
    }
}

void        FragTrap::takeDamage(unsigned int amount){
    int oldHp = this->_hitPoints;
    this->_hitPoints -= (amount - this->_armorDamageReduction);
    if (this->_hitPoints <= 0)
        this->_hitPoints = 0;
    std::cout << "FR4G-TP " << this->_name << " has taken a hit with " <<
                oldHp - this->_hitPoints << " points in damages!" << std::endl;
}

void        FragTrap::beRepaired(unsigned int amount){
    int         oldHp = this->_hitPoints;
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    
    std::cout << "FR4G-TP " << this->_name << " is getting cured, recovering " <<
                this->_hitPoints - oldHp << " hit points!" << std::endl;
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

int                 FragTrap::getHitPoints(void) const{
    return this->_hitPoints;
}

int                 FragTrap::getMaxHitPoints(void) const{
    return this->_maxHitPoints;
}

int                 FragTrap::getEnergyPoints(void) const{
    return this->_energyPoints;
}

int                 FragTrap::getMaxEnergyPoints(void) const{
    return this->_maxEnergyPoints;
};

unsigned int        FragTrap::getLevel(void) const{
    return this->_level;
}

std::string         FragTrap::getName(void) const{
    return this->_name;
}

unsigned int        FragTrap::getMeleeDamage(void) const{
    return this->_meleeAttackDamage;
}

unsigned int        FragTrap::getRangedDamage(void) const{
    return this->_rangedAttackDamage;
}

unsigned int        FragTrap::getArmorReduction(void) const{
    return this->_armorDamageReduction;
}
