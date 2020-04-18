#ifndef AINSTRUCTIONS_HPP
# define AINSTRUCTIONS_HPP

#include <vector>
#include <string>
#include "header.h"

class AInstructions;
typedef struct  s_instructions {
    char                symbol;
    AInstructions*      (*f_inst)(void); 
}               t_instructions;

class AInstructions {

    private:
        char                                    _symbol;
        static instructionIterator              _it;
        
        static std::vector<AInstructions*>      _vector;
        static std::string                      _program;
        static char *                           _ptrMem;
        static char                             _memory[30000];
        static t_instructions                   _actions[8];
        
        static AInstructions*       newDec();
        static AInstructions*       newInc();
        static AInstructions*       newInput();
        static AInstructions*       newOutput();
        static AInstructions*       newMoveLeft();
        static AInstructions*       newMoveRight();
        static AInstructions*       newOpenBracket();
        static AInstructions*       newCloseBracket();

    protected:
        AInstructions(void){}

    public:
        virtual ~AInstructions(void){}
        AInstructions(char const & symbol): _symbol(symbol) {}
        AInstructions(AInstructions const & src) { *this = src; }
        AInstructions &     operator=(AInstructions const & rhs);

        char    getSymbol(void) const { return this->_symbol; }

        static instructionIterator  &  getIt(void) { return AInstructions::_it; }
        static std::string &   getProgram(void) {return AInstructions::_program; }
        static std::vector<AInstructions*> &   getVector(void) {return AInstructions::_vector; }
        static char  * getPtrMem(void) { return AInstructions::_ptrMem; }
        static void    setPtrMem(char * value) { AInstructions::_ptrMem = value; }
        static  AInstructions*  newInstruction(char const c);

        virtual void    execute(void) = 0;



};


#endif