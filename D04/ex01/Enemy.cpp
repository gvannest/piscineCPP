#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(void){}

Enemy::Enemy(int hp, std::string const & type) :
    _type(type),
    _hp(hp)
{
}

Enemy::Enemy(Enemy const & instance){
    *this = instance;
}

Enemy::~Enemy(void){
}

Enemy &   Enemy::operator=(Enemy const & rhs){
    this->_type = rhs.getType();
    this->_hp = rhs.getHP();
    return *this;
}

std::string const   Enemy::getType(void) const{
    return this->_type;
}

int                 Enemy::getHP(void) const{
    return this->_hp;
}

void                Enemy::takeDamage(int damage){
    if (damage > 0){
        this->_hp -= damage;
        if (this->_hp <= 0){
            this->_hp = 0;
            this->~Enemy();
        }
    }
}

