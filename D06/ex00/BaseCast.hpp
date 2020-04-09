#ifndef BASECAST_HPP
# define BASECAST_HPP

# include <limits>
# include <iostream>

class BaseCast {

    private:
        double      _valueToCast;
        std::string _strInit;
        char        _precision;
        bool        _isInf;
        bool        _isNan;
        BaseCast(BaseCast const & src);
        BaseCast &    operator=(BaseCast const & rhs);

    protected:
        BaseCast(void);

    public:
        BaseCast(double const v, std::string const str, char const prec);
        virtual ~BaseCast(void) = 0;

        double      getValueToCast(void) const;
        bool        isInf(void) const;
        bool        isNan(void) const;
        char        getPrecision(void) const;

};

#endif