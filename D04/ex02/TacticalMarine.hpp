#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
    public:
        TacticalMarine(void);
        TacticalMarine(TacticalMarine const & instance);
        virtual ~TacticalMarine(void);
        TacticalMarine & operator=(TacticalMarine const & rhs);

        virtual TacticalMarine* clone(void) const;
        virtual void battleCry(void) const;
        virtual void rangedAttack(void) const;
        virtual void meleeAttack(void) const;

};

#endif