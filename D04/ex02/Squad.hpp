#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
    private:
        ISpaceMarine*       _squad[100];
        bool                _isInSquad(ISpaceMarine*) const;

    public:
        Squad(void);
        Squad(Squad const & instance);
        virtual ~Squad(void);
        Squad & operator=(Squad const & rhs);

        virtual int getCount(void) const;
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);

};

#endif