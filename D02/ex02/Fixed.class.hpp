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

        int         getRawBits(void) const;
        void        setRawBits(int const raw);

        float       toFloat(void) const;
        int         toInt(void) const;

        Fixed &     operator=(Fixed const & rhs);

        bool        operator>(Fixed const & rhs) const;
        bool        operator<(Fixed const & rhs) const;
        bool        operator>=(Fixed const & rhs) const;
        bool        operator<=(Fixed const & rhs) const;
        bool        operator==(Fixed const & rhs) const;
        bool        operator!=(Fixed const & rhs) const;

        Fixed       operator+(Fixed const & rhs);
        Fixed       operator-(Fixed const & rhs);
        Fixed       operator*(Fixed const & rhs);
        Fixed       operator/(Fixed const & rhs);

        Fixed &     operator++();
        Fixed       operator++(int);
        Fixed &     operator--();
        Fixed       operator--(int);

        static Fixed &            min(Fixed & i1, Fixed & i2);
        static Fixed &            max(Fixed & i1, Fixed & i2);
        static Fixed const &      min(Fixed const & i1, Fixed const & i2);
        static Fixed const &      max(Fixed const & i1, Fixed const & i2);

};

std::ostream &      operator<<(std::ostream & o, Fixed const & i);

#endif