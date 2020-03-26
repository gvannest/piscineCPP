#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    private:
        std::string const   _name;
        std::string         _type;

    public:
        Zombie(std::string const name, std::string const type);
        ~Zombie(void);

        void    advert(void) const;
};

#endif