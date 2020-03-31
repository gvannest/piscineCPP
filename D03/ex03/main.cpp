#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>
#include <time.h>

int     main(void){
    srand(time(NULL));
    FragTrap gogo;
    FragTrap jim = FragTrap("Jim");

    gogo.rangedAttack("Jim");
    jim.takeDamage(gogo.getRangedDamage());
    std::cout << "Jim hit points : " << jim.getHitPoints() << std::endl;

    jim.meleeAttack("Gogo");
    gogo.takeDamage(jim.getMeleeDamage());

    std::cout << "Gogo hit points : " << gogo.getHitPoints() << std::endl;
    gogo.beRepaired(20);
    std::cout << "Gogo hit points after repair : " << gogo.getHitPoints() << std::endl;
    gogo.beRepaired(50);

    gogo.vaulthunter_dot_exe("Jim");
    jim.takeDamage(30);
    std::cout << "Gogo energy points after spec attack : " << gogo.getEnergyPoints() << std::endl;
    std::cout << "Jim hit points after repair : " << jim.getHitPoints() << std::endl;

    gogo.vaulthunter_dot_exe("Jim");
    jim.takeDamage(60);
    std::cout << "Gogo energy points after spec attack : " << gogo.getEnergyPoints() << std::endl;
    std::cout << "Jim hit points after repair : " << jim.getHitPoints() << std::endl;
    
    gogo.vaulthunter_dot_exe("Jim");
    jim.takeDamage(60);
    std::cout << "Jim hit points after repair : " << jim.getHitPoints() << std::endl;
    gogo.vaulthunter_dot_exe("Jim");
    gogo.vaulthunter_dot_exe("Jim");

    std::cout << "-------------------------" << std::endl;
    ScavTrap door;
    ScavTrap bar = ScavTrap("bar");

    door.rangedAttack("bar");
    bar.takeDamage(door.getRangedDamage());
    std::cout << "bar hit points : " << bar.getHitPoints() << std::endl;

    bar.challengeNewcomer("Gogo");
    gogo.takeDamage(60);

    std::cout << "-------------------------" << std::endl;
    NinjaTrap ninja;
    NinjaTrap tenchu = NinjaTrap("Tenchu");
    std::cout << "ninja hit points begin : " << ninja.getHitPoints() << std::endl;
    jim.beRepaired(60);

    tenchu.ninjaShoebox(jim);
    std::cout << "Jim hit points : " << jim.getHitPoints() << std::endl;
    tenchu.ninjaShoebox(door);
    std::cout << "Door hit points : " << door.getHitPoints() << std::endl;
    tenchu.ninjaShoebox(ninja);
    std::cout << "ninja hit points : " << ninja.getHitPoints() << std::endl;

    jim.vaulthunter_dot_exe("Tenchu");
    tenchu.takeDamage(60);
    std::cout << "Tenchu hit points : " << tenchu.getHitPoints() << std::endl;

    std::cout << "-------------------------" << std::endl;


    return 0;
}