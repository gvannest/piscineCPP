#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Constructor called successfuly" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()) {
    *this = src;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Destructor called successfuly" << std::endl;
}

Bureaucrat &  Bureaucrat::operator=(Bureaucrat const & rhs){
    this->_grade = rhs.getGrade();
    return *this;
}

std::string const    Bureaucrat::getName(void) const{
    return this->_name;
}

int            Bureaucrat::getGrade(void) const{
    return this->_grade;
}

void            Bureaucrat::decGrade(void){
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void            Bureaucrat::incGrade(void){
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

std::ostream &      operator<<(std::ostream & o, Bureaucrat const & rhs){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
