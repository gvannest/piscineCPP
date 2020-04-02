#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

    private:

    public:
        PlasmaRifle(void);
        PlasmaRifle(PlasmaRifle const & instance);
        virtual ~PlasmaRifle(void);

        PlasmaRifle &   operator=(PlasmaRifle const & rhs);

        virtual void        attack(void);

};

#endif