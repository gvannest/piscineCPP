#ifndef OPENBRACKET_HPP
# define OPENBRACKET_HPP

#include "AInstructions.hpp"
#include <string>

class OpenBracket : virtual public AInstructions {

    private:
        size_t      _findClosingBracket(instructionIterator, instructionIterator);
        OpenBracket(void) {}

    public:
        ~OpenBracket(void) {}
        OpenBracket(char const & c) : AInstructions(c) {}
        OpenBracket(OpenBracket const & src): AInstructions(src) {}
        OpenBracket &   operator=(OpenBracket const & rhs);

        virtual void    execute(void);

};

#endif