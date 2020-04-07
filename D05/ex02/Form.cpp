#include "Form.hpp"
#include <iostream>

Form::
GradeTooHighException::GradeTooHighException(std::string const & message) : _message(message) {}

Form::
GradeTooLowException::GradeTooLowException(std::string const & message) : _message(message) {}

Form::
FormNotSignedException::FormNotSignedException(std::string const & message) : _message(message) {}

Form::Form(void)
: _name("default"), _target("default"), _signed(false), _gradeSigned(150), _gradeXecute(150)
{};

Form::Form(std::string const & name, std::string const & target, int const gradeSigned, int const gradeXecute) 
: _name(name), _target(target), _signed(false) {
    if (gradeSigned < 1 || gradeXecute < 1)
        throw Form::GradeTooHighException("Error : Grade is too high.");
    if (gradeSigned > 150 || gradeXecute > 150)
        throw Form::GradeTooLowException("Error : Grade is too low.");
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
    return this->_gradeXecute;
}

std::string   Form::getTarget(void) const{
    return this->_target;
}

void            Form::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() > this->_gradeSigned)
        throw Form::GradeTooLowException("Grade of bureaucrast too low to sign form.");
    this->_signed = true;
}

std::ostream &      operator<<(std::ostream & o, Form const & rhs){
    o << rhs.getName() << " form requires grade " << rhs.getGradeSigned()
    << " to be signed, and grade "<< rhs.getGradeXecute() << " to be executed.";
    return o;
}

void            Form::execute(Bureaucrat const & executor) const{
    if (!this->_signed)
        throw Form::FormNotSignedException("The form is not signed.");
    if (executor.getGrade() > this->_gradeXecute)
        throw Form::GradeTooLowException("Grade of executor is too low to execute the form.");
    this->action();
}

