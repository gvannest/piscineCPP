#include "MoveRight.hpp"

MoveRight &     MoveRight::operator=(MoveRight const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

void    MoveRight::execute(void) {
    char * current_ptr = AInstructions::getPtrMem();
    AInstructions::setPtrMem(current_ptr + 1);
    AInstructions::getIt()++;
}