#ifndef INPUT_HPP
# define INPUT_HPP

#include "AInstructions.hpp"

class Input : virtual public AInstructions {

    private:
        Input(void) {}

    public:
        ~Input(void) {}
        Input(char const & c) : AInstructions(c) {}
        Input(Input const & src): AInstructions(src) {}
        Input &   operator=(Input const & rhs);

        virtual void    execute(void);

};

#endif