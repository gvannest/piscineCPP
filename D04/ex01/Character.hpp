#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

    private:
        std::string         _name;
        int                 _ap;
        AWeapon *           _curWeapon;
        Character(void);

    public:
        Character(std::string const & name);
        Character(Character const & instance);
        virtual ~Character(void);

        Character &   operator=(Character const & rhs);

        void                recoverAP(void);
        void                equip(AWeapon* weapon);
        void                attack(Enemy* enemy);

        std::string         getName(void) const;
        int                 getAP(void) const;
        AWeapon *           getCurWeapon(void) const;
};

std::ostream &      operator<<(std::ostream & o, Character const & man);

#endif