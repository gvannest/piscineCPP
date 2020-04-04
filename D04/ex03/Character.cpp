#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(void){}

Character::Character(std::string const & name) : _name(name), _inventory() {}

Character::Character(Character const & src){
    *this = src;
}

Character::~Character(void){
    int i = 0;
    while (this->_inventory[i] && i < 4){
        delete this->_inventory[i];
        i++;
    }
}

Character & Character::operator=(Character const & rhs){
    if (this != &rhs){
        this->_name = rhs.getName();
        for (int i = 0; i < this->_getLength(); i++){
            delete this->_inventory[i];
            this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return *this;
}

int                     Character::_getLength(void) const{
    int i = 0;
    while (this->_inventory[i] && i < 4)
        i++;
    return i;
}

bool                    Character::_isInInv(AMateria * materia) const{
    for (int i = 0; i < 4; i++){
        if (this->_inventory[i] == materia)
            return true;
    }
    return false;
}

std::string const &     Character::getName() const{
    return this->_name;
}

void                    Character::equip(AMateria* m){
    int l = this->_getLength();
    if ( l < 4 && !_isInInv(m)){
        this->_inventory[l] = m;
    }
}

void                    Character::unequip(int idx){
    if (idx < 4 && idx >= 0 && this->_inventory[idx])
        this->_inventory[idx] = 0;
}

void                    Character::use(int idx, ICharacter& target){
    if (idx < 4 && idx >= 0 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}

