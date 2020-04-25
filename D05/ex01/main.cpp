# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
    try{
        Bureaucrat b2 = Bureaucrat("Gautier", 27);
        std::cout << b2 << std::endl;
        Form f1 = Form("admin_form", 178, 23);
        std::cout << f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Form f1 = Form("admin_form", 23, 0);
        std::cout << f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b1 = Bureaucrat("Gautier", 27);
        Form f1 = Form("admin_form", 30, 40);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << std::boolalpha << f1.getStatus() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b1 = Bureaucrat("Gautier", 27);
        Form f2 = Form("hr_form", 20, 40);
        std::cout << f2 << std::endl;
        b1.signForm(f2);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    

    return 0;
}