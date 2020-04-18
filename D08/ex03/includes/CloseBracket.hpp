#ifndef CLOSEBRACKET_HPP
# define CLOSEBRACKET_HPP

#include "AInstructions.hpp"
#include <string>

class CloseBracket : virtual public AInstructions {

    private:
        size_t      _findOpeningBracket(instructionIterator, instructionIterator);
        CloseBracket(void) {}

    public:
        ~CloseBracket(void) {}
        CloseBracket(char const & c) : AInstructions(c) {}
        CloseBracket(CloseBracket const & src): AInstructions(src) {}
        CloseBracket &   operator=(CloseBracket const & rhs);

        virtual void    execute(void);

};

#endif