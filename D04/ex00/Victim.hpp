#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim {

    private:
        std::string     _name;

        Victim(void);

    public:
        Victim(std::string name);
        Victim(Victim const & instance);
        virtual ~Victim(void);
        Victim &  operator=(Victim const & rhs);

        virtual void    getPolymorphed(void) const;
        std::string     getName(void) const;

};

std::ostream &      operator<<(std::ostream & o, Victim const & rhs);

#endif