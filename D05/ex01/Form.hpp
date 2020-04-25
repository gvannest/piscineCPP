#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Form
{
    private:
        std::string  const      _name; //cannot make it const otherwise impossible to override = operator
        bool                    _signed;
        int   const             _gradeSigned;
        int   const             _gradeXecute;

    public:
        Form(void);
        Form(std::string const & name, int const gradeSigned, int const gradeXecute);
        Form(Form const & src);
        ~Form(void);
        Form &  operator=(Form const & rhs);


        std::string         getName(void) const;
        bool                getStatus(void) const;
        int                 getGradeSigned(void) const;
        int                 getGradeXecute(void) const;

        void                 beSigned(Bureaucrat const &); 


    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: grade is too high";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: grade is too low";
            }
    };

};

std::ostream &      operator<<(std::ostream & o, Form const & rhs);

#endif