#include "Dec.hpp"
#include <climits>
#include <exception>
#include <stdexcept>

Dec &     Dec::operator=(Dec const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

void    Dec::execute(void) {
    char * current_ptr = AInstructions::getPtrMem();
    *current_ptr -= 1;
    AInstructions::getIt()++;
}