#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {

    private:
        static std::string  const   _randAttacks[5];

    public:
        FragTrap(std::string name = "gogo");
            
        FragTrap(FragTrap const & instance);
        ~FragTrap(void);
        FragTrap &  operator=(FragTrap const & rhs);

        void        vaulthunter_dot_exe(std::string const & target);

};

#endif