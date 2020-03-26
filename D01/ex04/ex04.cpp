#include <iostream>
#include <string>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string * strPtr = &str;
    std::string & strRef = str;
    std::cout << "str by pointer : " << *strPtr << std::endl;
    std::cout << "str by reference : " << strRef << std::endl;
    return (0);
}