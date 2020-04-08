#include "Intern.hpp"
#include <iostream>

Intern::
FormNotFoundException::FormNotFoundException(std::string const & message) : _message(message) {}


Intern::Intern(void) {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern::~Intern(void) {}

Intern &  Intern::operator=(Intern const & rhs){
    (void)rhs;
    return *this;
}

Form*        Intern::makeForm(std::string const & form_name, std::string const & target){
    std::string     formsAvailable[4] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    typedef Form*   (Intern::*newForm)(std::string const &);
    newForm     forms[4] = {&Intern::_newShrubbery, &Intern::_newRobotomy, &Intern::_newPresidential};
    for (int i = 0; i < 4; i++){
        if (form_name == formsAvailable[i]){
            Form * new_form = (this->*forms[i])(target);
            std::cout << "Intern creates " << *new_form << std::endl;
            return new_form;
        }
    }
    throw FormNotFoundException("Error: Form does not exist");
}

Form *     Intern::_newPresidential(std::string const & target){
    return (new PresidentialPardonForm(target));
}

Form *        Intern::_newRobotomy(std::string const & target){
    return (new RobotomyRequestForm(target));
}

Form *      Intern::_newShrubbery(std::string const & target){
    return (new ShrubberyCreationForm(target));
}

