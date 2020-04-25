#include "Form.hpp"
#include <iostream>

Form::Form(void)
: _name("default_form"), _signed(false), _gradeSigned(150), _gradeXecute(150)
{}

Form::Form(std::string const & name, int const gradeSigned, int const gradeXecute) 
: _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeXecute(gradeXecute) {
    if (gradeSigned < 1 || gradeXecute < 1)
        throw Form::GradeTooHighException();
    if (gradeSigned > 150 || gradeXecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & src)
: _name(src.getName()), _signed(false), _gradeSigned(src.getGradeSigned()), _gradeXecute(src.getGradeXecute())
{}

Form::~Form(void) {
}

Form &  Form::operator=(Form const & rhs){
    this->_signed = rhs.getStatus();
    return *this;
}

std::string  Form::getName(void) const{
    return this->_name;
}

bool            Form::getStatus(void) const{
    return this->_signed;
}

int         Form::getGradeSigned(void) const{
    return this->_gradeSigned;
}

int         Form::getGradeXecute(void) const{
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
