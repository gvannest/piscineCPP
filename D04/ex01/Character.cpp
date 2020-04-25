#include "Character.hpp"
#include <iostream>

Character::Character(void){}

Character::Character(std::string const & name) :
    _name(name),
    _ap(40),
    _curWeapon(0)
{
}

Character::Character(Character const & instance){
    *this = instance;
}

Character::~Character(void){}

Character &         Character::operator=(Character const & rhs){
    this->_name = rhs.getName();
    this->_ap = rhs.getAP();
    this->_curWeapon = rhs.getCurWeapon();
    return *this;
}

std::string         Character::getName(void) const{
    return this->_name;
}

int                 Character::getAP(void) const{
    return this->_ap;
}

AWeapon *           Character::getCurWeapon(void) const{
    return this->_curWeapon;
}

void                Character::recoverAP(void){
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void                Character::equip(AWeapon* weapon){
    this->_curWeapon = weapon;
}

void                Character::attack(Enemy* enemy){
    if (this->_curWeapon){
       if (this->_ap >= this->_curWeapon->getAPCost()){
            std::cout << this->_name << " attaque " << enemy->getType() << " with a " <<
            this->_curWeapon->getName() << std::endl;
            this->_curWeapon->attack();
            enemy->takeDamage(this->_curWeapon->getDamage());
            this->_ap -= this->_curWeapon->getAPCost();
        }
    }
}

std::ostream &      operator<<(std::ostream & o, Character const & man){
    if (man.getCurWeapon()){
        o << man.getName() << " has " << man.getAP() << " AP and carries a "
        << (man.getCurWeapon())->getName() << std::endl;
    }
    else {
        o << man.getName() << " has " << man.getAP() << " AP and is unarmed" << std::endl;
    }
    return o;
}

