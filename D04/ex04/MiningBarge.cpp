#include <iostream>
#include "MiningBarge.hpp"



MiningBarge::MiningBarge(void) : _barge() {
    std::cout << "MiningBarge defaut constructor called" << std::endl;
}

MiningBarge::MiningBarge(MiningBarge const & src){
    std::cout << "MiningBarge copy constructor called" << std::endl;
    *this = src;
}

MiningBarge::~MiningBarge(void){
    std::cout << "MiningBarge destructor called" << std::endl;
}

MiningBarge &       MiningBarge::operator=(MiningBarge const & rhs){
    std::cout << "MiningBarge assignment operator called" << std::endl;
    if (this != &rhs){
        for (int i = 0; i < 4; i++){
            this->_barge[i] = 0;
            if (rhs.getMiningLaser(i))
                this->_barge[i] = rhs.getMiningLaser(i)->clone();
        }
    }
    return *this;
}

int                 MiningBarge::_getLength(void) const{
    int i = 0;
    while (this->_barge[i] && i < 4)
        i++;
    return i;
}


IMiningLaser*       MiningBarge::getMiningLaser(int idx) const{
    if (idx < 4 && idx > 0)
        return this->_barge[idx];
    return 0;
}

void                MiningBarge::equip(IMiningLaser* laser){
    int l = this->_getLength();
    if (l < 4)
        this->_barge[l] = laser;
}

void                MiningBarge::mine(IAsteroid* aster) const{
    int i = 0;
    while (this->_barge[i] && i < 4)
        this->_barge[i++]->mine(aster);
}
