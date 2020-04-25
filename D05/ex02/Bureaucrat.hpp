#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
    private:
        std::string  const           _name;
        int                          _grade;
        Bureaucrat(void);

    public:
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat &  operator=(Bureaucrat const & rhs);

        std::string     getName(void) const;
        int             getGrade(void) const;

        void            incGrade(void); 
        void            decGrade(void);

        void            signForm(Form &) const;
        void            executeForm(Form const & form) const;


    class GradeTooHighException : public std::exception {
        private:
            std::string     _message;
            GradeTooHighException(void){}
        public:
            virtual ~GradeTooHighException(void) _NOEXCEPT{}
            GradeTooHighException(std::string const & message);
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

};

std::ostream &      operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif