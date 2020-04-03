#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void) {
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & instance){
    std::cout << "* teleports from space *" << std::endl;
    *this = instance;
}

AssaultTerminator::~AssaultTerminator(void) {
    std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs){
    (void)rhs;
    return *this;
}

AssaultTerminator* AssaultTerminator::clone(void) const{
    return (new AssaultTerminator(*this));
}

void    AssaultTerminator::battleCry(void) const{
    std::cout << "This code is unclean. Purify it !" << std::endl;
}

void    AssaultTerminator::rangedAttack(void) const{
    std::cout << "* does nothing *" << std::endl;
}

void    AssaultTerminator::meleeAttack(void) const{
    std::cout << "* attacks with chainfists *" << std::endl;
}




