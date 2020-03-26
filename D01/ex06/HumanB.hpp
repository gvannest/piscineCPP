#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

    private:
        std::string const   _name;
        Weapon  * _weapon;

    public:
        HumanB(std::string const name, Weapon * weapon = 0);
        ~HumanB(void);

        void        setWeapon(Weapon & weapon);
        void        attack(void) const;

};

#endif