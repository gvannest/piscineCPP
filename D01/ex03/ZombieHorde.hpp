#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>
#include <string>

class ZombieHorde {

    private:
        int const                   _n;
        Zombie                      *_zombies;
        static std::string const    _list_names[10];

    public:
        ZombieHorde(int const n);
        ~ZombieHorde(void);

        void  announce(void) const;

};

#endif