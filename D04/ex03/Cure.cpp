#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure"){}

Cure::Cure(Cure const & src) : AMateria(src){}

Cure::~Cure(void){}

Cure & Cure::operator=(Cure const & rhs){
    AMateria::operator=(rhs);
    return *this;
}

Cure*    Cure::clone() const{
    return (new Cure());
}

void    Cure::use(ICharacter& target){
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *" << std ::endl;
}
