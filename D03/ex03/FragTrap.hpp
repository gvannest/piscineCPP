#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {

    private:
        static std::string  const   _randAttacks[5];

    public:
        FragTrap(std::string name = "gogo", int hp = 100, int maxHp = 100, int ep = 100,
            int maxEp = 100, unsigned int mA = 30, unsigned int rA = 20,
            unsigned int aDR = 5);
            
        FragTrap(FragTrap const & instance);
        ~FragTrap(void);
        FragTrap &  operator=(FragTrap const & rhs);

        void        vaulthunter_dot_exe(std::string const & target);

};

#endif