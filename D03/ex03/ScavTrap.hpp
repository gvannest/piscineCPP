#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {

    private:
        static std::string  const   _randChallenges[5];

    public:
        ScavTrap(std::string name = "Door");
            
        ScavTrap(ScavTrap const & instance);
        ~ScavTrap(void);
        ScavTrap &  operator=(ScavTrap const & rhs);

        void        challengeNewcomer(std::string const & target);
};

#endif