#ifndef TESTCLASS_HPP
#define TESTCLASS_HPP

#include <iostream>

class Awesome
{

public:
    Awesome(void) : _n(42) {}
    int get(void) const { return this->_n; }

private:

    int _n;

};

std::ostream &      operator<<(std::ostream & o, Awesome const & rhs){
    o << rhs.get();
    return o;
}

template <typename T>
void print(T & x) {std::cout << x << std::endl; return ;}

#endif