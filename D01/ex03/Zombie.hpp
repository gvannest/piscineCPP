#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    private:
        std::string         _name;
        std::string         _type;

    public:
        Zombie(void);
        ~Zombie(void);

        void    advert(void) const;
        void    set_name(std::string const & name);
};

#endif