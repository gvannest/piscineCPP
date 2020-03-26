#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {

    private:
        std::string const   _name;
        Weapon  & _weapon;

    public:
        HumanA(std::string const name, Weapon & weapon);
        ~HumanA(void);

        void        setWeapon(Weapon & weapon);
        void        attack(void) const;

};

#endif