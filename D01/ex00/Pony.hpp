#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony {

    private:
        std::string const           _name;
        int const                   _age;
        static std::string const    _sound;
    
    public:
        Pony(std::string const name, int const age);
        ~Pony(void);

        std::string             get_name() const;
        int                     get_age() const;
        
        static std::string      make_sound();
};

#endif