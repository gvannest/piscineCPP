#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int const n) : _n(n){
    this->_zombies = new Zombie[n];
    srand (time(NULL));
    size_t rand_idx;
    for (int i = 0; i < n; i++){
        rand_idx = rand() % 10;
        this->_zombies[i].set_name(ZombieHorde::_list_names[rand_idx]);
    }
    std::cout << "A new Zombie horde has been created" << std::endl;
}

ZombieHorde::~ZombieHorde(void){
    delete [] this->_zombies;
    std::cout << "A Zombie horde has been destroyed" << std::endl;
}

void    ZombieHorde::announce(void) const{
    for (int i = 0; i < this->_n; i++){
        this->_zombies[i].advert();
    }
}

std::string const   ZombieHorde::_list_names[10] = {
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