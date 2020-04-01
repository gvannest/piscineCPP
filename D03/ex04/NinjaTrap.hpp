#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap : public virtual ClapTrap {

    public:
        NinjaTrap(std::string name = "Ninja");
        NinjaTrap(NinjaTrap const & instance);
        ~NinjaTrap(void);
        NinjaTrap &  operator=(NinjaTrap const & rhs);

        void        ninjaShoebox(FragTrap & clap);
        void        ninjaShoebox(ScavTrap & clap);
        void        ninjaShoebox(NinjaTrap & clap);

};

#endif