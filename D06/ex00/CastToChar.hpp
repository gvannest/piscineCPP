#ifndef CASTTOCHAR_HPP
# define CASTTOCHAR_HPP

#include "BaseCast.hpp"
# include <limits>
# include <iostream>

class CastToChar : public BaseCast {

    private:
        char        _result;
        CastToChar(void);
        CastToChar(CastToChar const & src);
        CastToChar &    operator=(CastToChar const & rhs);

    public:
        CastToChar(double const v, std::string const str, char const prec);
        virtual ~CastToChar(void);

        char        getResult(void) const;
};

std::ostream &      operator<<(std::ostream & o, CastToChar const & rhs);

#endif