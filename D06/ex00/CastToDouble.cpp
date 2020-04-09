#include "CastToDouble.hpp"

CastToDouble::CastToDouble(void){}

CastToDouble::CastToDouble(double const v, std::string const str, char const prec)
: BaseCast(v, str, prec)
{
}

CastToDouble::CastToDouble(CastToDouble const & src){
    *this = src;
}

CastToDouble::~CastToDouble(void) {}

CastToDouble &    CastToDouble::operator=(CastToDouble const & rhs){
    (void)rhs;
    return *this;
}

std::ostream &      operator<<(std::ostream & o, CastToDouble const & rhs){
    double v = rhs.getValueToCast();
    char prec = rhs.getPrecision();
    if (rhs.isInf()){
        if (v > 0)
            o << "+inf";
        if (v < 0)
            o << "-inf";
    }
    else if (rhs.isNan())
        o << "nan";
    else if (prec > 0)
        o << std::fixed << std::setprecision(prec) << static_cast<double>(v);
    else
        o << static_cast<double>(v) << ".0";
    return o;
}
