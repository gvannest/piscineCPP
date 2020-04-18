#ifndef DEC_HPP
# define DEC_HPP

#include "AInstructions.hpp"

class Dec : virtual public AInstructions {

    private:
        Dec(void) {}

    public:
        ~Dec(void) {}
        Dec(char const & c) : AInstructions(c) {}
        Dec(Dec const & src): AInstructions(src) {}
        Dec &   operator=(Dec const & rhs);


        virtual void    execute(void);

};

#endif