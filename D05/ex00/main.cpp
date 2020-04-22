# include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat b1 = Bureaucrat("Gautier", 27);
        std::cout << b1 << std::endl;
        b1.incGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b2 = Bureaucrat("Bob", 1);
        std::cout << b2 << std::endl;
        b2.incGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b3 = Bureaucrat("Foo", 150);
        std::cout << b3 << std::endl;
        b3.decGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b4 = Bureaucrat("Bar", 153);
        std::cout << b4 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b5 = Bureaucrat("Bar", 0);
        std::cout << b5 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}