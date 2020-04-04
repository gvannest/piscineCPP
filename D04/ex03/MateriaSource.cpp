#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : _learntMaterias() {}

MateriaSource::MateriaSource(MateriaSource const & src){
    *this = src;
}

MateriaSource::~MateriaSource(void){}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs){
    if (this != &rhs){
        for (int i = 0; i < this->_getLength(); i++){
            delete this->_learntMaterias[i];
            this->_learntMaterias[i] = rhs._learntMaterias[i]->clone();
        }
    }
    return *this;
}

int             MateriaSource::_getLength(void) const{
    int i = 0;
    while (this->_learntMaterias[i] && i < 4)
        i++;
    return i;
}

void            MateriaSource::learnMateria(AMateria* materia){
    int l = this->_getLength();
    if (l < 4)
        this->_learntMaterias[l] = materia;
}

AMateria*       MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if (this->_learntMaterias[i]->getType() == type)
            return this->_learntMaterias[i]->clone();
    }
    return 0;
}
