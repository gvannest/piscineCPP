#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
#include <iostream>

class Fixed {

    private:
        int                 _fixedPointValue;
        static char const   _fracBits;

    public:
        Fixed(void);
        Fixed(int const & n);
        Fixed(float const & f);
        Fixed(Fixed const & i);
        ~Fixed(void);

        Fixed &     operator=(Fixed const & rhs);

        int         getRawBits(void) const;
        void        setRawBits(int const raw);

        float       toFloat(void) const;
        int         toInt(void) const;

};

std::ostream &      operator<<(std::ostream & o, Fixed const & i);

#endif