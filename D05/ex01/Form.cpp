#include "Form.hpp"
#include <iostream>

Form::Form(void)
: _name("default_form"), _signed(false), _gradeSigned(150), _gradeXecute(150)
{}

Form::Form(std::string const & name, int const gradeSigned, int const gradeXecute) 
: _name(name), _signed(false) {
    if (gradeSigned < 1 || gradeXecute < 1)
        throw Form::GradeTooHighException();
    if (gradeSigned > 150 || gradeXecute > 150)
        throw Form::GradeTooLowException();
    this->_gradeSigned = gradeSigned;
    this->_gradeXecute = gradeXecute;
    std::cout << "Constructor called successfuly" << std::endl;
}

Form::Form(Form const & src) {
    *this = src;
}

Form::~Form(void) {
    std::cout << "Destructor called successfuly" << std::endl;
}

Form &  Form::operator=(Form const & rhs){
    this->_name = rhs.getName();
    this->_gradeSigned = rhs.getGradeSigned();
    this->_gradeXecute = rhs.getGradeXecute();
    return *this;
}

std::string     Form::getName(void) const{
    return this->_name;
}

bool            Form::getStatus(void) const{
    return this->_signed;
}

int            Form::getGradeSigned(void) const{
    return this->_gradeSigned;
}

int            Form::getGradeXecute(void) const{
    return this->_gradeSigned;
}

void            Form::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() > this->_gradeSigned)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

std::ostream &      operator<<(std::ostream & o, Form const & rhs){
    o << rhs.getName() << " form requires grade " << rhs.getGradeSigned()
    << " to be signed, and grade "<< rhs.getGradeXecute() << " to be executed.";
    return o;
}
