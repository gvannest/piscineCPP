#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria {

    private:
        std::string         _type;
        unsigned int        _xp;
        AMateria(void);

    public:
            AMateria(std::string const & type);
            AMateria(AMateria const & materia);
            virtual ~AMateria();
            AMateria & operator=(AMateria const & rhs);

            std::string const & getType() const;
            unsigned int getXP() const;

            virtual AMateria* clone() const = 0;
            virtual void use(ICharacter& target);
};

#endif