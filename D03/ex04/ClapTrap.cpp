#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

ClapTrap::ClapTrap(void) :  _hitPoints(0),
                            _maxHitPoints(0),
                            _energyPoints(0),
                            _maxEnergyPoints(0),
                            _level(0),
                            _name("default"),
                            _meleeAttackDamage(0),
                            _rangedAttackDamage(0),
                            _armorDamageReduction(0)
{
    std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(int hp, int maxHp, int ep, int maxEp, unsigned int mA, unsigned int rA,
                unsigned int aDR, std::string name) :   _hitPoints(hp),
                                                        _maxHitPoints(maxHp),
                                                        _energyPoints(ep),
                                                        _maxEnergyPoints(maxEp),
                                                        _level(1),
                                                        _name(name),
                                                        _meleeAttackDamage(mA),
                                                        _rangedAttackDamage(rA),
                                                        _armorDamageReduction(aDR)
{
    std::cout << "ClapTrap parameter constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & instance){
    std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
    *this = instance;
}

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap destructor called. " << this->_name << " has died." << std::endl;
}

void        ClapTrap::rangedAttack(std::string const & target) const{
        std::cout << "CL4P-TP " << this->_name << " launched a ranged attack, on " << 
            target << " causing " <<
            this->_rangedAttackDamage << " points in damages!" << std::endl;
}

void        ClapTrap::meleeAttack(std::string const & target) const{
    std::cout << "CL4P-TP " << this->_name << " launched a melee attack, on " << 
            target << " causing " <<
            this->_meleeAttackDamage << " points in damages!" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount){
    int oldHp = this->_hitPoints;
    this->_hitPoints -= (amount - this->_armorDamageReduction);
    if (this->_hitPoints <= 0)
        this->_hitPoints = 0;
    std::cout << "CL4P-TP " << this->_name << " has taken a hit with " <<
                oldHp - this->_hitPoints << " points in damages!" << std::endl;
}

void        ClapTrap::beRepaired(unsigned int amount){
    int         oldHp = this->_hitPoints;
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    
    std::cout << "CL4P-TP " << this->_name << " is getting cured, recovering " <<
                this->_hitPoints - oldHp << " energy points!" << std::endl;
}

ClapTrap &  ClapTrap::operator=(ClapTrap const & rhs){
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

int                 ClapTrap::getHitPoints(void) const{
    return this->_hitPoints;
}

int                 ClapTrap::getMaxHitPoints(void) const{
    return this->_maxHitPoints;
}

int                 ClapTrap::getEnergyPoints(void) const{
    return this->_energyPoints;
}

int                 ClapTrap::getMaxEnergyPoints(void) const{
    return this->_maxEnergyPoints;
};

unsigned int        ClapTrap::getLevel(void) const{
    return this->_level;
}

std::string         ClapTrap::getName(void) const{
    return this->_name;
}

unsigned int        ClapTrap::getMeleeDamage(void) const{
    return this->_meleeAttackDamage;
}

unsigned int        ClapTrap::getRangedDamage(void) const{
    return this->_rangedAttackDamage;
}

unsigned int        ClapTrap::getArmorReduction(void) const{
    return this->_armorDamageReduction;
}

void                ClapTrap::setEnergyPoints(int ep){
    this->_energyPoints = ep;
}
