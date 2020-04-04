#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::Ice(Ice const & src) : AMateria(src){}

Ice::~Ice(void){}

Ice & Ice::operator=(Ice const & rhs){
    AMateria::operator=(rhs);
    return *this;
}

Ice*    Ice::clone() const{
    return (new Ice);
}

void    Ice::use(ICharacter& target){
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std ::endl;
}
