#include "Inc.hpp"
#include <climits>
#include <exception>
#include <stdexcept>

Inc &     Inc::operator=(Inc const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

void    Inc::execute(void) {
    char * current_ptr = AInstructions::getPtrMem();
    *current_ptr += 1;
    AInstructions::getIt()++;
}