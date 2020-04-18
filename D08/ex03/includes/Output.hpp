#ifndef OUTPUT_HPP
# define OUTPUT_HPP

#include "AInstructions.hpp"

class Output : virtual public AInstructions {

    private:
        Output(void) {}

    public:
        ~Output(void) {}
        Output(char const & c) : AInstructions(c) {}
        Output(Output const & src): AInstructions(src) {}
        Output &   operator=(Output const & rhs);

        virtual void    execute(void);

};

#endif