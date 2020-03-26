#include "ZombieHorde.hpp"
#include <iostream>

int main(void){
    std::cout << "--- Creation of the horde ---" << std::endl;
    ZombieHorde * new_horde = new ZombieHorde(12);
    std::cout << "--- Announcement of everyone in the horde ---" << std::endl;
    new_horde->announce();
    std::cout << "--- Destroy the horde ---" << std::endl;
    delete new_horde;
    return 0;
}