#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class FragTrap {

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

        static std::string  const   _randAttacks[5];

    public:
        FragTrap(std::string name = "Gogo");
        FragTrap(FragTrap const & instance);
        ~FragTrap(void);
        FragTrap &  operator=(FragTrap const & rhs);

        void        rangedAttack(std::string const & target) const;
        void        meleeAttack(std::string const & target) const;
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        void        vaulthunter_dot_exe(std::string const & target);

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