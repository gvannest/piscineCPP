#include <iostream>
#include "Asteroid.hpp"


Asteroid::Asteroid(void) : _name("Asteroid") {
    std::cout << "Asteroid defaut constructor called" << std::endl;
}

Asteroid::Asteroid(Asteroid const & src){
    std::cout << "Asteroid copy constructor called" << std::endl;
    *this = src;
}

Asteroid::~Asteroid(void){
    std::cout << "Asteroid destructor called" << std::endl;
}

Asteroid &         Asteroid::operator=(Asteroid const & rhs){
    std::cout << "Asteroid assignment operator called" << std::endl;
    this->_name = rhs.getName();
    return *this;
}

std::string     Asteroid::getName() const{
    return this->_name;
}

std::string     Asteroid::beMined(DeepCoreMiner *) const{
    return "Dragonite";
}

std::string     Asteroid::beMined(StripMiner *) const{
    return "Flavium";
}