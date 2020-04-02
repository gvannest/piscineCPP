#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {

    private:

    public:
        PowerFist(void);
        PowerFist(PowerFist const & instance);
        virtual ~PowerFist(void);

        PowerFist &   operator=(PowerFist const & rhs);

        virtual void        attack(void);

};

#endif