#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include "Victim.hpp"

class Peon : public Victim {

    private:
        Peon(void);

    public:
        Peon(std::string name);
        Peon(Peon const & instance);
        ~Peon(void);
        Peon &  operator=(Peon const & rhs);

        virtual void     getPolymorphed(void) const;
};

#endif