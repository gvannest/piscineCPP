#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {

    private:
        int                 _rawBits;
        static char const   _bitsNumber;

    public:
        Fixed(void);
        Fixed(Fixed const & i);
        ~Fixed(void);

        Fixed &     operator=(Fixed const & rhs);

        int         getRawBits(void) const;

        void        setRawBits(int const raw);

};

#endif