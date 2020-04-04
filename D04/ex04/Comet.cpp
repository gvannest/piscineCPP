#include <iostream>
#include "Comet.hpp"



Comet::Comet(void) : _name("Comet") {
    std::cout << "Comet defaut constructor called" << std::endl;
}

Comet::Comet(Comet const & src){
    std::cout << "Comet copy constructor called" << std::endl;
    *this = src;
}

Comet::~Comet(void){
    std::cout << "Comet destructor called" << std::endl;
}

Comet &         Comet::operator=(Comet const & rhs){
    std::cout << "Comet assignment operator called" << std::endl;
    this->_name = rhs.getName();
    return *this;
}

std::string     Comet::getName() const{
    return this->_name;
}

std::string     Comet::beMined(DeepCoreMiner *) const{
    return "Mithril";
}

std::string     Comet::beMined(StripMiner *) const{
    return "Tartarite";
}