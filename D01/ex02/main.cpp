#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main(void){

    std::cout << "---Test simple Zombie creation---" << std::endl;
    Zombie  * simpleZombie = new Zombie("Foo", "42 student");
    simpleZombie->advert();
    std::cout << std::endl;

    std::cout << "---Test Zombie Event---" << std::endl;
    std::cout << std::endl;
    ZombieEvent * newEvent = new ZombieEvent();
    std::cout << std::endl;
    std::cout << "1. Create a Zombie of default standard type" << std::endl;
    Zombie  * stdZombie = newEvent->newZombie("Bar");
    stdZombie->advert();
    std::cout << std::endl;
    std::cout << "2. Test set type and random Zombie" << std::endl;
    newEvent->setZombieType("Nazi");
    Zombie * naziZombie = newEvent->randomChump();
    std::cout << std::endl;
    std::cout << "---Kill zombies---" << std::endl;
    delete simpleZombie;
    delete stdZombie;
    delete naziZombie;
    delete newEvent;
}