#include "OpenBracket.hpp"
#include <string>
#include <stack>
#include <iostream>
#include "header.h"

OpenBracket &     OpenBracket::operator=(OpenBracket const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

size_t      OpenBracket::_findClosingBracket(instructionIterator it, instructionIterator itE){
    size_t i = 0;
    std::stack<AInstructions*> stack;
    while (it != itE){
        if ((*it)->getSymbol() == '[')
            stack.push(*it);
        else if ((*it)->getSymbol() == ']'){
            stack.pop();
            if (stack.empty()){
                return (i);
            }
        }
        i++;
        it++;
    }
    throw std::logic_error("Error: missing closing parentheses");
}

void    OpenBracket::execute(void) {
    if (*(AInstructions::getPtrMem()) == 0){// si la valeur en memoire est nulle, on saute apres la closing bracket
        size_t i = this->_findClosingBracket(AInstructions::getIt(), AInstructions::getVector().end());
        AInstructions::getIt() += i; // on jump à l'instruction closing bracket
    }
    AInstructions::getIt()++;
}