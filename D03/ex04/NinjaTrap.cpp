#include "NinjaTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

NinjaTrap::NinjaTrap(std::string name)
: ClapTrap(60, 60, 120, 120, 60, 5, 0, name, "I AM A NINJA. POK. YOU DEAD.") {
    std::cout << "NinjaTrap default constructor called for " << this->getName() << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & instance){
    std::cout << "NinjaTrap copy constructor called for " << this->getName() << std::endl;
    *this = instance;
}

NinjaTrap::~NinjaTrap(void){
    std::cout << "NinjaTrap destructor called. " << this->getName() << " has died." << std::endl;
}

void        NinjaTrap::ninjaShoebox(ClapTrap & clap){
    std::cout << "NinjaTrap CLAP CLAP! " << this->getName() << " has launched a FULL BLOWN attack on "
            << clap.getName() << " inflicting him 80 points in damages!" << std::endl;
    clap.takeDamage(80);
}

void        NinjaTrap::ninjaShoebox(FragTrap & frag){
    std::cout << "NinjaTrap FRAG FRAG! " << this->getName() << " has launched a shit bag attack on "
            << frag.getName() << " inflicting him 20 points in damages!" << std::endl;
    frag.takeDamage(20);
}

void        NinjaTrap::ninjaShoebox(ScavTrap & scav){
    std::cout << "NinjaTrap SCAV SCAV! " << this->getName() << " has launched a toad attack on "
            << scav.getName() << " inflicting him 25 points in damages!" << std::endl;
    scav.takeDamage(25);
}

void        NinjaTrap::ninjaShoebox(NinjaTrap & ninja){
    std::cout << "NinjaTrap NINJA NINJA! " << this->getName() << " has launched a developer socks attack on "
            << ninja.getName() << " inflicting him 10 points in damages!" << std::endl;
    ninja.takeDamage(10);
}

NinjaTrap &  NinjaTrap::operator=(NinjaTrap const & rhs){
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

