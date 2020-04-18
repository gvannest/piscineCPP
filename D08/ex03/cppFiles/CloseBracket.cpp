#include "CloseBracket.hpp"
#include <string>
#include <stack>
#include <vector>
#include <iostream>

CloseBracket &     CloseBracket::operator=(CloseBracket const & rhs){
    AInstructions::operator=(rhs);
    return *this;
}

size_t          CloseBracket::_findOpeningBracket(instructionIterator it, instructionIterator itB){
    size_t i = 0;
    std::stack<AInstructions*> stack;
    while (it != itB){
        if ((*it)->getSymbol() == ']')
            stack.push(*it);
        else if ((*it)->getSymbol() == '['){
            stack.pop();
            if (stack.empty()){
                return (i);
            }
        }
        i++;
        it--;
    }
    throw std::logic_error("Error: missing opening parentheses");
}

void    CloseBracket::execute(void) {
    if (*(AInstructions::getPtrMem())){// si la valeur en memoire est non nulle, on revient apres l'opening bracket
        size_t i = this->_findOpeningBracket(AInstructions::getIt(), AInstructions::getVector().begin());
        AInstructions::getIt() -= i; // On se met a l'opening bracket
    }
    AInstructions::getIt()++;
}