#ifndef INC_HPP
# define INC_HPP


#include "AInstructions.hpp"

class Inc : virtual public AInstructions {

    private:
        Inc(void) {}

    public:
        ~Inc(void) {}
        Inc(char const & c) : AInstructions(c) {}
        Inc(Inc const & src): AInstructions(src) {}
        Inc &   operator=(Inc const & rhs);

        virtual void    execute(void);

};

#endif