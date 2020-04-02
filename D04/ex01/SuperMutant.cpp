#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & instance) : Enemy(instance){
    std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::~SuperMutant(void){}

SuperMutant &   SuperMutant::operator=(SuperMutant const & rhs){
    this->Enemy::operator=(rhs);
    return *this;
}

void                SuperMutant::takeDamage(int damage){
    damage -= 3;
    if (damage > 0){
        this->_hp -= damage;
        if (this->_hp < 0)
            this->_hp = 0;
        std::cout << "SuperMutant of type " << this->_type << " has taken "
        << damage << " points in damages!" << std::endl;
    }
}

