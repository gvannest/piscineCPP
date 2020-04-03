#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
    public:
        AssaultTerminator(void);
        AssaultTerminator(AssaultTerminator const & instance);
        virtual ~AssaultTerminator(void);
        AssaultTerminator & operator=(AssaultTerminator const & rhs);

        virtual AssaultTerminator* clone(void) const;
        virtual void battleCry(void) const;
        virtual void rangedAttack(void) const;
        virtual void meleeAttack(void) const;

};

#endif