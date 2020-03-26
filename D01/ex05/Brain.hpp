#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

    private:

    public:
        Brain(void);
        ~Brain(void);

        std::string const     identify(void) const;
};

#endif