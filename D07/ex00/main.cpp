#include <iostream>
#include <iomanip>

template< typename T >
void    swap(T & a, T & b){
    T   c;
    c = a;
    a = b;
    b = c;
}

template< typename T >
T const &   min(T const & a, T const & b){
    return (a < b ? a : b);
}

template< typename T >
T const &   max(T const & a, T const & b){
    return (a > b ? a : b);
}


int main(void){
    int a = 23;
    int b = 42;

    std::cout << "Minimum between a: " << a << " and b: " << b << std::endl;
    std::cout << min<int>(a, b) << std::endl << std::endl;

    swap<int>(a, b);
    std::cout << "Maximum between a: " << a << " and b: " << b << std::endl;
    std::cout << max<int>(a, b) << std::endl << std::endl;

    float c = 36.75f;
    float d = 36.75f;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Minimum between c: " << c << " and d: " << d << std::endl;
    std::cout << min<float>(c, d) << std::endl << std::endl;
    d = 45.0f;
    std::cout << "Maximum between c: " << c << " and d: " << d << std::endl;
    std::cout << max<float>(c, d) << std::endl << std::endl;
    swap<float>(c, d);
    std::cout << "Minimum between c: " << c << " and d: " << d << std::endl;
    std::cout << min<float>(c, d) << std::endl << std::endl;

    return 0;
}
