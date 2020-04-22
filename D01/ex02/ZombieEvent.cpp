#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void) : _type("standard"){
    std::cout << "A new Zombie event has been created" << std::endl;
}

ZombieEvent::~ZombieEvent(void){
    std::cout << "A Zombie event has been destroyed" << std::endl;
}

void                ZombieEvent::setZombieType(std::string type){
    this->_type = type;
}

Zombie              *ZombieEvent::newZombie(std::string name) const{
    Zombie * zombie = new Zombie(name, this->_type);
    return zombie;
}

Zombie              *ZombieEvent::randomChump(void){
    srand(time(NULL));
    size_t rand_idx = rand() % 10;
    Zombie * zombie = this->newZombie(ZombieEvent::_list_names[rand_idx]);
    zombie->advert();
    return zombie;
}

std::string const   ZombieEvent::_list_names[10] = {
    "Dominique",
    "Fred",
    "Camille",
    "Marshall",
    "Pascal",
    "Maurice",
    "Alfonse",
    "Johnny",
    "Patrick",
    "Philippe",
};
