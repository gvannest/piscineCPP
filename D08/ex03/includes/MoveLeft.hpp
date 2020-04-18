#ifndef MOVELEFT_HPP
# define MOVELEFT_HPP

#include "AInstructions.hpp"

class MoveLeft : virtual public AInstructions {

    private:
        MoveLeft(void) {}

    public:
        ~MoveLeft(void) {}
        MoveLeft(char const & c) : AInstructions(c) {}
        MoveLeft(MoveLeft const & src): AInstructions(src) {}
        MoveLeft &   operator=(MoveLeft const & rhs);

        virtual void    execute(void);

};

#endif