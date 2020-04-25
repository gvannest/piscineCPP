# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

int main(){

    Bureaucrat  gogo("Gogo", 70);
    Bureaucrat  foo("Foo", 10);
    Intern      idiot;

    OfficeBlock bureau(&idiot, &gogo, &foo);
    OfficeBlock bureau2(&idiot, &foo, &gogo);

    try {
        bureau.doBureaucracy("shrubbery creation", "Bobby");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    try {
        bureau.doBureaucracy("robert", "Bobby");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    try {
        bureau.doBureaucracy("robotomy request", "Bobby");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    try {
        bureau.doBureaucracy("presidential pardon", "Bobby");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    Bureaucrat superman("John", 1);
    bureau.setExecutor(&superman);
    bureau.setSignatory(&superman);
    
    try {
        bureau.doBureaucracy("presidential pardon", "Bobby");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}