#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "IAsteroid.hpp"

class Asteroid : public IAsteroid
{
    private:
        std::string     _name;

    public:
        Asteroid(void);
        Asteroid(Asteroid const & src);
        virtual ~Asteroid();
        Asteroid &     operator=(Asteroid const & rhs);

        virtual std::string getName() const;
        
        virtual std::string beMined(DeepCoreMiner *) const;
        virtual std::string beMined(StripMiner *) const;
};

#endif