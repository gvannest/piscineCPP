# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"
# include "Form.hpp"

int main(){
    Intern  gvann;
    gvann.makeForm("shrubbery creation", "Foo");
    
    try {
        gvann.makeForm("Bar", "robotomy request");
    }
    catch (Intern::FormNotFoundException & e) {
        std::cout << e.what() << std::endl;
    }
    gvann.makeForm("robotomy request", "Foo");
    gvann.makeForm("presidential pardon", "Foo");

    return 0;
}