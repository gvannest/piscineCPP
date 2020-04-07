# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
    Bureaucrat b1 = Bureaucrat("Gautier", 72);   
    Bureaucrat b2 = Bureaucrat("Bob", 4);

    ShrubberyCreationForm s1 = ShrubberyCreationForm("Maison");
    RobotomyRequestForm r1 = RobotomyRequestForm("Dom");
    PresidentialPardonForm p1 = PresidentialPardonForm("John");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << s1 << std::endl;
    std::cout << r1 << std::endl;
    std::cout << p1 << std::endl;

    b1.signForm(s1);
    b1.signForm(r1);
    b1.signForm(p1);

    b1.executeForm(s1);
    b1.executeForm(r1);
    b1.executeForm(p1);

    b2.signForm(s1);
    b2.signForm(r1);
    b2.signForm(p1);

    b2.executeForm(s1);
    b2.executeForm(r1);
    b2.executeForm(p1);

    return 0;
}