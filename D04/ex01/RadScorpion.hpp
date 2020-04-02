#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <string>
#include "Enemy.hpp"

class RadScorpion : public Enemy {

    private:

    public:
        RadScorpion(void);
        RadScorpion(RadScorpion const & instance);
        virtual ~RadScorpion(void);
        RadScorpion &   operator=(RadScorpion const & rhs);

};

#endif