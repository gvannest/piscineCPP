#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
    {
        Weapon        club = Weapon("crude spiked club");
        Weapon        hammer = Weapon("Big hammer");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        bob.setWeapon(hammer);
        bob.attack();
        std::cout << "Club : " << club.getType() << std::endl;
    } {
        Weapon        club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}