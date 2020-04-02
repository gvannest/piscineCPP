#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <string>
#include "Enemy.hpp"

class SuperMutant : public Enemy {

    private:

    public:
        SuperMutant(void);
        SuperMutant(SuperMutant const & instance);
        virtual ~SuperMutant(void);
        SuperMutant &   operator=(SuperMutant const & rhs);


        virtual void        takeDamage(int damage);
};

#endif