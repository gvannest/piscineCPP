#include "Output.hpp"
#include <iostream>

Output &     Output::operator=(Output const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}



void    Output::execute(void){
    std::cout << *(AInstructions::getPtrMem());
    AInstructions::getIt()++;
}