#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "AInstructions.hpp"

void    ft_del(AInstructions* instruction){
    delete instruction;
}

void    display(AInstructions * instruction){
    std::cout << instruction->getSymbol();
}

void    parseProgram(std::string program, std::vector<AInstructions*> & vector){
    for (std::string::const_iterator itB = program.begin(); itB != program.end(); ++itB){
        if (*itB == '+' || *itB == '-' || *itB == '.' || *itB == ',' || *itB == '<' || *itB == '>'
        || *itB == '[' || *itB == ']'){
            vector.push_back(AInstructions::newInstruction(*itB));
        }
    }
}

std::string     ft_read_file(char *path){
    std::ifstream ifs(path);
    std::string line;
    std::string program;
    if (!ifs.is_open())
        throw std::invalid_argument("File not found");
    while (std::getline(ifs, line)){
        program += line;
    }
    ifs.close();
    return program;
}

int     main(int argc, char **argv){
    if (argc != 2)
        std::cout << "Usage : ./mindopen [file]" << std::endl;
    else {
        std::vector<AInstructions *>  instVector = AInstructions::getVector();
        AInstructions::getProgram() = ft_read_file(argv[1]);
        parseProgram(AInstructions::getProgram(), AInstructions::getVector());
        AInstructions::getIt() = AInstructions::getVector().begin();
        instructionIterator it = AInstructions::getIt();
        while(AInstructions::getIt() != AInstructions::getVector().end()){
            it = AInstructions::getIt();
            (*it)->execute();
        }
        for_each(AInstructions::getVector().begin(), AInstructions::getVector().end(), ft_del);
        }
    return (0);
}