#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class StripMiner : public IMiningLaser
{
    public:
        StripMiner(void);
        StripMiner(StripMiner const & src);
        virtual ~StripMiner();
        StripMiner &     operator=(StripMiner const & rhs);

        virtual void mine(IAsteroid* asteroid);
        virtual StripMiner*   clone(void) const;

};

#endif