#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

class ScavTrap {

    private:
        int          _hitPoints;
        int          _maxHitPoints;
        int          _energyPoints;
        int          _maxEnergyPoints;
        unsigned int _level;
        std::string _name;
        unsigned int _meleeAttackDamage;
        unsigned int _rangedAttackDamage;
        unsigned int _armorDamageReduction;

        static std::string  const   _randChallenges[5];

    public:
        ScavTrap(std::string name = "Door");
        ScavTrap(ScavTrap const & instance);
        ~ScavTrap(void);
        ScavTrap &  operator=(ScavTrap const & rhs);

        void        rangedAttack(std::string const & target) const;
        void        meleeAttack(std::string const & target) const;
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        void        challengeNewcomer(std::string const & target);

        int                 getHitPoints(void) const;
        int                 getMaxHitPoints(void) const;
        int                 getEnergyPoints(void) const;
        int                 getMaxEnergyPoints(void) const;
        unsigned int        getLevel(void) const;
        std::string         getName(void) const;
        unsigned int        getMeleeDamage(void) const;
        unsigned int        getRangedDamage(void) const;
        unsigned int        getArmorReduction(void) const;

};

#endif