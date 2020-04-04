#ifndef COMET_HPP
# define COMET_HPP

#include "IAsteroid.hpp"

class Comet : public IAsteroid
{
    private:
        std::string     _name;

    public:
        Comet(void);
        Comet(Comet const & src);
        virtual ~Comet();
        Comet &     operator=(Comet const & rhs);

        virtual std::string getName() const;

        virtual std::string beMined(DeepCoreMiner *) const;
        virtual std::string beMined(StripMiner *) const;
};

#endif