#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
#include "Victim.hpp"


class Sorcerer {

    private:
        std::string     _name;
        std::string     _title;

        Sorcerer(void);

    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const & instance);
        ~Sorcerer(void);
        Sorcerer &  operator=(Sorcerer const & rhs);

        void            polymorph(Victim const & victim) const;

        std::string     getName(void) const;
        std::string     getTitle(void) const;

};

std::ostream &      operator<<(std::ostream & o, Sorcerer const & rhs);

#endif