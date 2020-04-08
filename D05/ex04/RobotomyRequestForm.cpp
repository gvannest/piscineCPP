#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

#include "Form.hpp"

RobotomyRequestForm::RobotomyRequestForm(void){}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
: Form("Robotomy request", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) 
: Form::Form(src) {
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm &  RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
    this->Form::operator=(rhs);
    return *this;
}

void               RobotomyRequestForm::action(void) const{
    std::cout << "Tatatata... (bruit de perceuse)" << std::endl;
    std::cout << this->getTarget() << " has been robotomized" << std::endl;
}
