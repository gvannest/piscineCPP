#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {

    private:
        static std::string  const   _randChallenges[5];

    public:
        ScavTrap(std::string name = "john", int ep = 50, int maxEp = 50,
                unsigned int mA = 20, unsigned int rA = 15, unsigned int aDR = 3);
        ScavTrap(ScavTrap const & instance);
        ~ScavTrap(void);
        ScavTrap &  operator=(ScavTrap const & rhs);

        void        challengeNewcomer(std::string const & target);
};

#endif