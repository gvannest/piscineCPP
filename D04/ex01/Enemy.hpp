#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy {

    private:
        Enemy(void);

    protected:
        std::string         _type;
        int                 _hp;


    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const & instance);
        virtual ~Enemy(void);

        Enemy &   operator=(Enemy const & rhs);

        std::string const   getType(void) const;
        int                 getHP(void) const;

        virtual void        takeDamage(int damage);
};

#endif