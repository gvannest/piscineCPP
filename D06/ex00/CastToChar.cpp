#include "CastToChar.hpp"

CastToChar::CastToChar(void){}

CastToChar::CastToChar(double const v, std::string const str, char const prec)
: BaseCast(v, str, prec)
{
    if (!(v < CHAR_MIN || v > CHAR_MAX || this->isInf() || this->isNan()))
        this->_result = static_cast<char>(v);
}

CastToChar::CastToChar(CastToChar const & src){
    *this = src;
}

CastToChar::~CastToChar(void) {}

CastToChar &    CastToChar::operator=(CastToChar const & rhs){
    (void)rhs;
    return *this;
}

char        CastToChar::getResult(void) const{
    return this->_result;
}   

std::ostream &      operator<<(std::ostream & o, CastToChar const & rhs){
    double v = rhs.getValueToCast();
    if (v < CHAR_MIN || v > CHAR_MAX || rhs.isInf() || rhs.isNan())
        o << "impossible";
    else if (!std::isprint(rhs.getResult()))
        o << "non displayable";
    else
        o << rhs.getResult();
    return o;
}
