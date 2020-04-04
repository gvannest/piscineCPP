#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

    private:
        AMateria*      _learntMaterias[4];

        int             _getLength() const;

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & src);
        virtual ~MateriaSource();
        MateriaSource &     operator=(MateriaSource const & rhs);

        virtual void learnMateria(AMateria* materia);
        virtual AMateria* createMateria(std::string const & type);

};

#endif