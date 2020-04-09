#include "CastToFloat.hpp"

CastToFloat::CastToFloat(void){}

CastToFloat::CastToFloat(double const v, std::string const str, char const prec)
: BaseCast(v, str, prec)
{
    if (!(this->isInf() || this->isNan()))
        this->_result = static_cast<float>(v);
}

CastToFloat::CastToFloat(CastToFloat const & src){
    *this = src;
}

CastToFloat::~CastToFloat(void) {}

CastToFloat &    CastToFloat::operator=(CastToFloat const & rhs){
    (void)rhs;
    return *this;
}

float        CastToFloat::getResult(void) const{
    return this->_result;
}   

std::ostream &      operator<<(std::ostream & o, CastToFloat const & rhs){
    double v = rhs.getValueToCast();
    char prec = rhs.getPrecision();
    if (rhs.isInf()){
        if (v > 0)
            o << "+inff";
        if (v < 0)
            o << "-inff";
    }
    else if (rhs.isNan())
        o << "nanf";
    else if (prec > 0)
        o << std::fixed << std::setprecision(prec) << rhs.getResult() << 'f';
    else
        o << rhs.getResult() << ".0f";
    return o;

}
