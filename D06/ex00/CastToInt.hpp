#ifndef CASTTOINT_HPP
# define CASTTOINT_HPP

#include "BaseCast.hpp"
# include <limits>
# include <iostream>

class CastToInt : public BaseCast {

    private:
        int        _result;
        CastToInt(void);
        CastToInt(CastToInt const & src);
        CastToInt &    operator=(CastToInt const & rhs);

    public:
        CastToInt(double const v, std::string const str, char const prec);
        virtual ~CastToInt(void);

        int        getResult(void) const;
};

std::ostream &      operator<<(std::ostream & o, CastToInt const & rhs);

#endif