#ifndef CURE_HPP
#define CURE_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {

    private:

    public:
        Cure(void);
        Cure(Cure const & src);
        virtual ~Cure();
        Cure & operator=(Cure const & rhs);

        virtual Cure* clone() const;
        virtual void use(ICharacter& target);
};

#endif