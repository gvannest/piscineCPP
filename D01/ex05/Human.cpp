#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void){
    this->_brain = new Brain();
}

Human::~Human(void){
    delete this->_brain;
}

std::string const  Human::identify(void) const{
    return this->_brain->identify();
}

Brain const & Human::getBrain(void) const{
    return *(this->_brain);
}

