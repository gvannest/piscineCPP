#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
    private:
        IMiningLaser*       _barge[4];

        int                 _getLength(void) const;

    public:
        MiningBarge(void);
        MiningBarge(MiningBarge const & src);
        virtual ~MiningBarge();
        MiningBarge &     operator=(MiningBarge const & rhs);

        void    equip(IMiningLaser*);
        void    mine(IAsteroid*) const;

        IMiningLaser*       getMiningLaser(int idx) const;

};

#endif