#ifndef CASTTOFLOAT_HPP
# define CASTTOFLOAT_HPP

#include "BaseCast.hpp"
# include <limits>
# include <iostream>
# include <iomanip>

class CastToFloat : public BaseCast {

    private:
        float        _result;
        CastToFloat(void);
        CastToFloat(CastToFloat const & src);
        CastToFloat &    operator=(CastToFloat const & rhs);

    public:
        CastToFloat(double const v, std::string const str, char const prec);
        virtual ~CastToFloat(void);

        float        getResult(void) const;
};

std::ostream &      operator<<(std::ostream & o, CastToFloat const & rhs);

#endif