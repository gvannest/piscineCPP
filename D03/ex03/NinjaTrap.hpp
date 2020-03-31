#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap : public ClapTrap {

    public:
        NinjaTrap(std::string name = "Ninja", int hp = 60, int maxHp = 60, int ep = 120,
            int maxEp = 120, unsigned int mA = 60, unsigned int rA = 5,
            unsigned int aDR = 0);

        NinjaTrap(NinjaTrap const & instance);
        ~NinjaTrap(void);
        NinjaTrap &  operator=(NinjaTrap const & rhs);

        void        ninjaShoebox(FragTrap & clap);
        void        ninjaShoebox(ScavTrap & clap);
        void        ninjaShoebox(NinjaTrap & clap);

};

#endif