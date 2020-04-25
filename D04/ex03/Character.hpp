#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {

    private:
        std::string         _name;
        AMateria*           _inventory[4];

        bool                _isInInv(AMateria * materia) const;   
        Character(void);

    protected:
        int                 _getLength(void) const;   

    public:
        Character(std::string const & name);
        Character(Character const & src);
        virtual ~Character();
        Character & operator=(Character const & rhs);

        virtual std::string const & getName() const;

        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};

#endif