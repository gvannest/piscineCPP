#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>
#include <string>

class ZombieEvent {

    private:
        std::string                 _type;
        static std::string const    _list_names[10];

    public:
        ZombieEvent(void);
        ~ZombieEvent(void);

        void                        setZombieType(std::string type);
        Zombie                      *newZombie(std::string name) const;
        Zombie                      *randomChump(void);
};

#endif