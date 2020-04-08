#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::
GradeTooHighException::GradeTooHighException(std::string const & message) : _message(message) {}

Bureaucrat::
GradeTooLowException::GradeTooLowException(std::string const & message) : _message(message) {}

Bureaucrat::Bureaucrat(void) : _name("defaut"), _grade(150){}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Error: Grade is too high (must be > 0).");
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException("Error: Grade is too low (must be <= 150).");
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
    *this = src;
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat &  Bureaucrat::operator=(Bureaucrat const & rhs){
    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
    return *this;
}

std::string    Bureaucrat::getName(void) const{
    return this->_name;
}

int            Bureaucrat::getGrade(void) const{
    return this->_grade;
}

void            Bureaucrat::decGrade(void){
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException("Error: Grade is too low (must be <= 151>).");
    this->_grade++;
}

void            Bureaucrat::incGrade(void){
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException("Error: Grade is too high (must be > 0).");
    this->_grade--;
}

void            Bureaucrat::signForm(Form & form) const{
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signs form " << form.getName() <<std::endl;
    }
    catch (Form::GradeTooLowException const & e){
        std::cout << this->_name << " can't sign form " << form.getName() <<
        " because " << e.what() << std::endl;
        std::cout <<"Grade " << form.getGradeSigned() << " is required." << std::endl;
    }
}

void            Bureaucrat::executeForm(Form const & form) const{
    try{
        form.execute(*this);
        std::cout << this->_name << " has executed " << form.getName() << " successfuly." << std::endl;
    }
    catch(Form::FormNotSignedException & e){
        std::cout << this->_name << " can't execute form because " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e){
        std::cout << this->_name << " can't execute form because " << e.what() << std::endl;
        std::cout << "Grade " << form.getGradeXecute() << " is required." << std::endl;
    }
}


std::ostream &      operator<<(std::ostream & o, Bureaucrat const & rhs){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
