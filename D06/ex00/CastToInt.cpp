#include "CastToInt.hpp"

CastToInt::CastToInt(void){}

CastToInt::CastToInt(double const v, std::string const str, char const prec)
: BaseCast(v, str, prec)
{
    if (!(v < INT_MIN || v > INT_MAX || this->isInf() || this->isNan()))
        this->_result = static_cast<int>(v);
}

CastToInt::CastToInt(CastToInt const & src){
    *this = src;
}

CastToInt::~CastToInt(void) {}

CastToInt &    CastToInt::operator=(CastToInt const & rhs){
    (void)rhs;
    return *this;
}

int        CastToInt::getResult(void) const{
    return this->_result;
}   

std::ostream &      operator<<(std::ostream & o, CastToInt const & rhs){
    double v = rhs.getValueToCast();
    if (v < INT_MIN || v > INT_MAX || rhs.isInf() || rhs.isNan())
        o << "impossible";
    else
        o << rhs.getResult();
    return o;
    
}
