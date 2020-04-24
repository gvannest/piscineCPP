#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class SuperTrap : public FragTrap, public NinjaTrap {

    public:
        SuperTrap(std::string name = "Zouper");
        SuperTrap(SuperTrap const & instance);
        ~SuperTrap(void);
        SuperTrap &  operator=(SuperTrap const & rhs);

        void        rangedAttack(std::string const &) const;
        void        meleeAttack(std::string const &) const;

};

#endif