#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: Form("Shrubbery creation", target, 145, 137)
{
    std::cout << "Shrubbery creation form successfuly created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) 
: Form::Form(src) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm &  ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
    this->Form::operator=(rhs);
    return *this;
}

void               ShrubberyCreationForm::action(void) const{
    std::ofstream   ofs(this->getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
    if (ofs.fail()){
        throw std::logic_error("Error with the output file.");
    }
    ofs << "          1          " << std::endl;
    ofs << "         / \\         " << std::endl;
    ofs << "        /   \\        " << std::endl;
    ofs << "       /     \\       " << std::endl;
    ofs << "      2       3      " << std::endl;
    ofs << "     / \\     / \\     " << std::endl;
    ofs << "    4   5   6   7    " << std::endl;
    ofs << "   /   / \\     / \\   " << std::endl;
    ofs << "  8   9   1   2   3  " << std::endl;
    ofs << "     /               " << std::endl;
    ofs << "    4                " << std::endl;
    ofs.close(); 
    return;
}
