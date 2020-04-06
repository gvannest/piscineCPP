# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
    Bureaucrat  b1;
    Form        f1;
    try{
        b1 = Bureaucrat("Gautier", 27);
        std::cout << b1 << std::endl;
        f1 = Form("admin_form", 178, 23);
        std::cout << f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        f1 = Form("admin_form", 23, 0);
        std::cout << f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        f1 = Form("admin_form", 30, 40);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
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