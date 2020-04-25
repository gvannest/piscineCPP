#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* moi = new Character("moi");

    AMateria* tmp;
    AMateria* tmp2;
    tmp = src->createMateria("ice");
    moi->equip(tmp);
    tmp2 = src->createMateria("cure");
    moi->equip(tmp2);

    ICharacter* bob = new Character("bob");

    moi->use(0, *bob);
    moi->use(1, *bob);
    moi->use(0, *bob);
    std::cout << tmp->getXP() << std::endl;
    std::cout << tmp2->getXP() << std::endl;

    delete bob;
    delete moi;
    delete src;

    return 0;
}