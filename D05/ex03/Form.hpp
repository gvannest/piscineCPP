#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Form
{
    
    private:
        std::string  const          _name; //cannot make it const otherwise impossible to override = operator
        std::string                 _target;
        bool                        _signed;
        int  const                  _gradeSigned;
        int  const                  _gradeXecute;

    public:
        Form(void);
        Form(std::string const & name, std::string const & target, int const gradeSigned, int const gradeXecute);
        Form(Form const & src);
        virtual ~Form(void);

        Form &  operator=(Form const & rhs);

        std::string          getName(void) const;
        bool                 getStatus(void) const;
        int                  getGradeSigned(void) const;
        int                  getGradeXecute(void) const;
        std::string          getTarget(void) const;

        void                 beSigned(Bureaucrat const &);
        virtual void         action(void) const = 0;
        void                 execute(Bureaucrat const & executor) const;


    class GradeTooHighException : public std::exception {
        private:
            std::string    _message;
            GradeTooHighException(void){}
        public:
            GradeTooHighException(std::string const & message);
            virtual ~GradeTooHighException(void) _NOEXCEPT{}
            virtual const char* what() const throw(){
                return _message.c_str();
            }
    };

    class GradeTooLowException : public std::exception {
        private:
            std::string     _message;
            GradeTooLowException(void){}
        public:
            virtual ~GradeTooLowException(void) _NOEXCEPT{}
            GradeTooLowException(std::string const & message);
            virtual const char* what() const throw(){
                return _message.c_str();
            }
    };

    class FormNotSignedException : public std::exception {
        private:
            std::string     _message;
            FormNotSignedException(void){}
        public:
            virtual ~FormNotSignedException(void) _NOEXCEPT{}
            FormNotSignedException(std::string const & message);
            virtual const char* what() const throw(){
                return _message.c_str();
            }
    };

};

std::ostream &      operator<<(std::ostream & o, Form const & rhs);

#endif