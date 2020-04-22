#include "ZombieHorde.hpp"
#include <iostream>

int main(void){
    std::cout << "--- Creation of the horde ---" << std::endl;
    ZombieHorde * new_horde = new ZombieHorde(6);
    std::cout << std::endl << "--- Announcement of everyone in the horde ---" << std::endl;
    new_horde->announce();
    std::cout << std::endl << "--- Destroy the horde ---" << std::endl;
    delete new_horde;
    return 0;
}