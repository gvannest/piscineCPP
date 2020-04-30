#ifndef TESTCLASS_HPP
#define TESTCLASS_HPP

#include <iostream>

class Awesome
{

public:
    Awesome(int n) : _n(n) {}
    Awesome(void) : _n(0) {}

    bool operator==(Awesome const & rhs) { return (this->_n == rhs._n);}
    bool operator!=(Awesome const & rhs) { return (this->_n != rhs._n);}
    bool operator>(Awesome const & rhs) { return (this->_n > rhs._n);}
    bool operator<(Awesome const & rhs) { return (this->_n < rhs._n);}
    bool operator>=(Awesome const & rhs) { return (this->_n >= rhs._n);}
    bool operator<=(Awesome const & rhs) { return (this->_n <= rhs._n);}

    int     n(void) const { return this->_n; }
    Awesome &   operator=(Awesome const & rhs) { this->_n = rhs.n(); return *this; }

private:

    int _n;

};

std::ostream &      operator<<(std::ostream & o, Awesome const & rhs){
    o << rhs.n();
    return o;
}

#endif