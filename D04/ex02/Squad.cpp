#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad(void) : _squad() {

}

Squad::Squad(Squad const & instance){
    int i = 0;
    while (this->_squad[i] && i < 100){
        delete this->_squad[i];
        this->_squad[i] = instance.getUnit(i)->clone();
        i++;
    }
}

Squad::~Squad(void) {
    for (int i = 0; i < this->getCount(); i++)
        delete this->_squad[i];
}

Squad &     Squad::operator=(Squad const & rhs){
    int i = 0;
    while (this->_squad[i] && i < 100){
        this->_squad[i] = rhs.getUnit(i)->clone();
        i++;
    }
    return *this;
}

int             Squad::getCount(void) const{
    int i = 0;
    while (this->_squad[i] && i < 100)
        i++;
    return i;
}

ISpaceMarine*   Squad::getUnit(int u) const{
    if (u < 100)
        return this->_squad[u];
    return 0;
}

bool            Squad::_isInSquad(ISpaceMarine* marine) const{
    for (int i = 0; i < this->getCount(); i++) {
        if (this->_squad[i] == marine)
            return true;
    }
    return false;
}

int             Squad::push(ISpaceMarine* marine){
    int i = -1;
    if (marine && !_isInSquad(marine)){
        i = this->getCount();
        this->_squad[i] = marine;
    }
    return i;
}
