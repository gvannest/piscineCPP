#include <iostream>
#include "StripMiner.hpp"

StripMiner::StripMiner(void) {
    std::cout << "StripMiner defaut constructor called" << std::endl;
}

StripMiner::StripMiner(StripMiner const & src){
    std::cout << "StripMiner copy constructor called" << std::endl;
    *this = src;
}

StripMiner::~StripMiner(void){
    std::cout << "StripMiner destructor called" << std::endl;
}

StripMiner &    StripMiner::operator=(StripMiner const & rhs){
    (void)rhs;
    std::cout << "StripMiner assignment operator called" << std::endl;
    return *this;
}    

void            StripMiner::mine(IAsteroid* asteroid){
    std::cout << "* strip mining ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}

StripMiner*   StripMiner::clone(void) const{
    return (new StripMiner(*this));
}