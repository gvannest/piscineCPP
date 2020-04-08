#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        Form *      _newPresidential(std::string const &);
        Form *      _newRobotomy(std::string const &);
        Form *      _newShrubbery(std::string const &);

    public:
        Intern(void);
        Intern(Intern const & src);
        ~Intern(void);

        Intern &  operator=(Intern const & rhs);

        Form*        makeForm(std::string const & form_name, std::string const & target);

    class FormNotFoundException : public std::exception {
        private:
            std::string     _message;
            FormNotFoundException(void){}
        public:
            virtual ~FormNotFoundException(void) _NOEXCEPT{}
            FormNotFoundException(std::string const & message);
            virtual const char* what() const throw(){
                return _message.c_str();
            }
    };

};

#endif