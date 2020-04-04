#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class DeepCoreMiner : public IMiningLaser
{
    private:


    public:
        DeepCoreMiner(void);
        DeepCoreMiner(DeepCoreMiner const & src);
        virtual ~DeepCoreMiner();
        DeepCoreMiner &     operator=(DeepCoreMiner const & rhs);

        virtual void mine(IAsteroid* asteroid);
        virtual DeepCoreMiner*   clone(void) const;


};

#endif