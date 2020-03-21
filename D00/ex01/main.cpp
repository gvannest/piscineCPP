# include "Contact.class.hpp"

int     main(void){

    std::string input;    

    while (1){
        std::cout << "Please enter a command : "; 
        std::cin >> input;
        if (!input.compare("EXIT"))
            return 0;
    }

    return 0;
}