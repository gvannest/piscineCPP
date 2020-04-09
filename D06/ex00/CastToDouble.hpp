#ifndef CASTTODOUBLE_HPP
# define CASTTODOUBLE_HPP

#include "BaseCast.hpp"
# include <limits>
# include <iostream>
# include <iomanip>

class CastToDouble : public BaseCast {

    private:
        CastToDouble(void);
        CastToDouble(CastToDouble const & src);
        CastToDouble &    operator=(CastToDouble const & rhs);

    public:
        CastToDouble(double const v, std::string const str, char const prec);
        virtual ~CastToDouble(void);

};

std::ostream &      operator<<(std::ostream & o, CastToDouble const & rhs);

#endif