#include "Input.hpp"
#include <string>
#include <iostream>

Input &     Input::operator=(Input const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

void    Input::execute(void) {
    char * current_ptr = AInstructions::getPtrMem();
    std::string input;
    std::cin >> input;
    if (input.length() > 1)
        throw std::range_error("Error: only one character should be entered");
    else if (input.length() == 1)
        *current_ptr = input.at(0);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    AInstructions::getIt()++;
}