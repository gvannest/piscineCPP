#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon {

    private:
        std::string         _name;
        int                 _apcost;
        int                 _damage;

        AWeapon(void);

    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const & instance);
        virtual ~AWeapon(void);
        
        AWeapon &   operator=(AWeapon const & rhs);

        std::string const   getName(void) const;
        int                 getAPCost(void) const;
        int                 getDamage(void) const;

        virtual void        attack(void) = 0;
};

#endif