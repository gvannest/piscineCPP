#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
    private:
        std::string  const      _name;
        int                     _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat &  operator=(Bureaucrat const & rhs);

        std::string  const   getName(void) const;
        int                  getGrade(void) const;

        void            incGrade(void); 
        void            decGrade(void);

        void            signForm(Form &) const;


    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: grade is too high (must be > 0)";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: grade is too low (must be <= 150)";
            }
    };

};

std::ostream &      operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif