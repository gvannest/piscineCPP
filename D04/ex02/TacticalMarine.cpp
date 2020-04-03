#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine(void) {
    std::cout << "Tactical Marine ready for action !" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & instance){
    std::cout << "Tactical Marine ready for action !" << std::endl;
    *this = instance;
}

TacticalMarine::~TacticalMarine(void) {
    std::cout << "Aaargh..." << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs){
    (void)rhs;
    return *this;
}

TacticalMarine* TacticalMarine::clone(void) const{
    return (new TacticalMarine(*this));
}

void    TacticalMarine::battleCry(void) const{
    std::cout << "For the Holy PLOT !" << std::endl;
}

void    TacticalMarine::rangedAttack(void) const{
    std::cout << "* attacks with a bolter *" << std::endl;
}

void    TacticalMarine::meleeAttack(void) const{
    std::cout << "* attacks with a chainsword *" << std::endl;
}




