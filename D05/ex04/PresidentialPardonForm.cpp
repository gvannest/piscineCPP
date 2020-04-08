#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm(void){}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: Form("Presidential pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) 
: Form::Form(src) {
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm &  PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
    this->Form::operator=(rhs);
    return *this;
}

void               PresidentialPardonForm::action(void) const{
    std::cout << this->getTarget() << " a été pardonné par Zafod Beeblebrox" << std::endl;
}
