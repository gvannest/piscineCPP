#ifndef MOVERIGHT_HPP
# define MOVERIGHT_HPP

#include "AInstructions.hpp"

class MoveRight : virtual public AInstructions {

    private:
        MoveRight(void) {}

    public:
        ~MoveRight(void) {}
        MoveRight(char const & c) : AInstructions(c) {}
        MoveRight(MoveRight const & src): AInstructions(src) {}
        MoveRight &   operator=(MoveRight const & rhs);

        virtual void    execute(void);

};

#endif