#include <iostream>
#include <iomanip>
#include <string>

#include "CastToChar.hpp"
#include "CastToInt.hpp"
#include "CastToDouble.hpp"
#include "CastToFloat.hpp"

static char     getPrecision(std::string s){
    size_t idxPt;
    if ((idxPt = s.find('.')) == std::string::npos)
        return -1;
    if (s.back() == 'f')
        return (s.substr(idxPt + 1).length() - 1);
    return (s.substr(idxPt + 1).length());
}

static void     ft_convert(std::string s){
    double value;

    char prec = getPrecision(s);
    value = atof(s.c_str());
    

    CastToChar c(value, s, prec);
    CastToInt i(value, s, prec);
    CastToFloat f(value, s, prec);
    CastToDouble d(value, s, prec);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;

}

int main(int argc, char **argv){

    if (argc != 2){
        std::cout << "Usage: ./convert [str]" << std::endl;
        return 0;
    }
    ft_convert(argv[1]);
    
    return 0;
}