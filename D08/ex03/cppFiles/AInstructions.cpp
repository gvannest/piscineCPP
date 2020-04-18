#include "AInstructions.hpp"
#include "Dec.hpp"
#include "Inc.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "MoveLeft.hpp"
#include "MoveRight.hpp"
#include "OpenBracket.hpp"
#include "CloseBracket.hpp"

#include <exception>
#include <queue>
#include <iostream>


char            AInstructions::_memory[30000] = {};

std::string     AInstructions::_program;

std::vector<AInstructions*>   AInstructions::_vector;

instructionIterator              AInstructions::_it;


char *          AInstructions::_ptrMem = AInstructions::_memory;

t_instructions   AInstructions::_actions[8] = {
    {'-', &AInstructions::newDec},
    {'+', &AInstructions::newInc},
    {',', &AInstructions::newInput},
    {'.', &AInstructions::newOutput},
    {'<', &AInstructions::newMoveLeft},
    {'>', &AInstructions::newMoveRight},
    {'[', &AInstructions::newOpenBracket},
    {']', &AInstructions::newCloseBracket}
};

AInstructions &     AInstructions::operator=(AInstructions const & rhs){
    this->_symbol = rhs.getSymbol();
    this->_it = rhs.getIt();
    return *this;
}

AInstructions*  AInstructions::newInstruction(char const c){
    for (int i = 0; i < 8; i++){
        if (AInstructions::_actions[i].symbol == c)
            return(AInstructions::_actions[i].f_inst());
    }
    throw std::logic_error("Error in newInstruction function. Character not found");
}

AInstructions*       AInstructions::newDec() { return new Dec('-'); }
AInstructions*       AInstructions::newInc() { return new Inc('+'); }
AInstructions*       AInstructions::newInput() { return new Input(','); }
AInstructions*       AInstructions::newOutput() { return new Output('.'); }
AInstructions*       AInstructions::newMoveLeft() { return new MoveLeft('<'); }
AInstructions*       AInstructions::newMoveRight() { return new MoveRight('>'); }
AInstructions*       AInstructions::newOpenBracket() { return new OpenBracket('['); }
AInstructions*       AInstructions::newCloseBracket() { return new CloseBracket(']'); }