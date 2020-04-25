#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & instance) : Enemy(instance){
    std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::~SuperMutant(void){
    std::cout << "Aaargh..." << std::endl;
}

SuperMutant &   SuperMutant::operator=(SuperMutant const & rhs){
    this->Enemy::operator=(rhs);
    return *this;
}

void                SuperMutant::takeDamage(int damage){
    this->Enemy::takeDamage(damage - 3);
}

