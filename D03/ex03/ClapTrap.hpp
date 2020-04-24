#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {

    protected:
        int          _hitPoints;
        int          _maxHitPoints;
        int          _energyPoints;
        int          _maxEnergyPoints;
        unsigned int _level;
        std::string _name;
        unsigned int _meleeAttackDamage;
        unsigned int _rangedAttackDamage;
        unsigned int _armorDamageReduction;
        std::string                 _msg;


    public:
        ClapTrap(void);
        ClapTrap(int hp, int maxHp, int ep, int maxEp, unsigned int mA, unsigned int rA,
                unsigned int aDR, std::string name, std::string msg);
        ClapTrap(ClapTrap const & instance);
        ~ClapTrap(void);
        ClapTrap &  operator=(ClapTrap const & rhs);

        void        rangedAttack(std::string const &) const;
        void        meleeAttack(std::string const &) const;
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        int                 getHitPoints(void) const;
        int                 getMaxHitPoints(void) const;
        int                 getEnergyPoints(void) const;
        int                 getMaxEnergyPoints(void) const;
        unsigned int        getLevel(void) const;
        std::string         getName(void) const;
        unsigned int        getMeleeDamage(void) const;
        unsigned int        getRangedDamage(void) const;
        unsigned int        getArmorReduction(void) const;

        void                setEnergyPoints(int ep);
};

#endif