#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(void){}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
    _name(name),
    _apcost(apcost),
    _damage(damage)
{
}

AWeapon::AWeapon(AWeapon const & instance){
    *this = instance;
}

AWeapon::~AWeapon(void){}

AWeapon &   AWeapon::operator=(AWeapon const & rhs){
    this->_name = rhs.getName();
    this->_apcost = rhs.getAPCost();
    this->_damage = rhs.getDamage();
    return *this;
}


std::string const   AWeapon::getName(void) const{
    return this->_name;
}

int                 AWeapon::getAPCost(void) const{
    return this->_apcost;
}

int                 AWeapon::getDamage(void) const{
    return this->_damage;
}

