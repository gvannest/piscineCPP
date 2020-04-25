#include <iostream>
#include "DeepCoreMiner.hpp"

#include <iostream>

DeepCoreMiner::DeepCoreMiner(void) {
    std::cout << "DeepCoreMiner defaut constructor called" << std::endl;
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const & src){
    std::cout << "DeepCoreMiner copy constructor called" << std::endl;
    *this = src;
}

DeepCoreMiner::~DeepCoreMiner(void){
    std::cout << "DeepCoreMiner destructor called" << std::endl;
}

DeepCoreMiner &    DeepCoreMiner::operator=(DeepCoreMiner const & rhs){
    (void)rhs;
    std::cout << "DeepCoreMiner assignment operator called" << std::endl;
    return *this;
}    

void        DeepCoreMiner::mine(IAsteroid* asteroid){
    std::cout << "* mining deep ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}

DeepCoreMiner*   DeepCoreMiner::clone(void) const{
    return (new DeepCoreMiner());
}
