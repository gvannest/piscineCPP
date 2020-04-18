#include "MoveLeft.hpp"
#include <string>
#include <iostream>

MoveLeft &     MoveLeft::operator=(MoveLeft const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

void    MoveLeft::execute(void) {
    char * current_ptr = AInstructions::getPtrMem();
    AInstructions::setPtrMem(current_ptr - 1);
    AInstructions::getIt()++;
}