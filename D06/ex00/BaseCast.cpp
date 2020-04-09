#include "BaseCast.hpp"

BaseCast::BaseCast(void){}

BaseCast::BaseCast(double const v, std::string const str, char const prec)
: _valueToCast(v), _strInit(str), _precision(prec)
{
    this->_isInf = str.find("inf", 0) != std::string::npos ? true : false;
    this->_isNan = str.find("nan", 0) != std::string::npos ? true : false;
}

BaseCast::BaseCast(BaseCast const & src){
    *this = src;
}

BaseCast::~BaseCast(void) {}

BaseCast &    BaseCast::operator=(BaseCast const & rhs){
    (void)rhs;
    return *this;
}

double      BaseCast::getValueToCast(void) const{
    return this->_valueToCast;
}

bool        BaseCast::isInf(void) const{
    return this->_isInf;
}   

bool        BaseCast::isNan(void) const{
    return this->_isNan;
}   

char        BaseCast::getPrecision(void) const{
    return this->_precision;
}   