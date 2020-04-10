#include "Array.hpp"
#include <string>

int main(void){

    Array<int>      int_array(10);
    Array<char>     char_array(8);

    Array<int>      int_array2;
    std::cout << "Address of int_array2 : " << int_array2.getArray() << std::endl;
    std::cout << "Size of int_array2 : " << int_array2.size() << std::endl;

    int_array[5] = 12;
    int_array[7] = 9;

    try {
        int_array[15] = -5;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "int_array : " << int_array << std::endl;

    Array<int>      int_array3(int_array);
    std::cout << "int_array3 : " << int_array3 << std::endl;
    int_array3[0] = -5;
    std::cout << "int_array after modif: " << int_array << std::endl;
    std::cout << "int_array3 after modif: " << int_array3 << std::endl;

    char_array[3] = 52;
    char_array[5] = '!';
    try {
        char_array[8] = 60;
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "char_array : " << char_array << std::endl;

    Array<std::string>      arrayOfStr(5);
    arrayOfStr[2] = "I love ponies.";
    arrayOfStr[4] = "I hate pineapples";
    std::cout << "arrayOfStr : " << arrayOfStr << std::endl;

}