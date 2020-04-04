#ifndef ICE_HPP
#define ICE_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria {

    private:

    public:
        Ice(void);
        Ice(Ice const & src);
        virtual ~Ice();
        Ice & operator=(Ice const & rhs);

        virtual Ice* clone() const;
        virtual void use(ICharacter& target);
};

#endif