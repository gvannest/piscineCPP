#include <iostream>
#include <cstdlib>

template <typename T>
void    iter(T * tab, size_t size, void (*f)(T &)){
    for (size_t i = 0; i < size; i++)
        (*f)(tab[i]);
}

void    square_int(int & a){
    a *= a;
}

template< typename U>
void    add_one(U & u){
    u += 1;
}

int main(void){
    char    tab_char[] = "Hello World!";
    int     tab[8] = {3, 5, -2, 8, 1, 10, 7, -5};

    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;
    iter<int>(tab, 8, &square_int);
    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;
    iter<int>(tab, 8, &add_one);
    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;

    std::cout << tab_char << std::endl;
    iter<char>(tab_char, 12, &add_one);
    std::cout << tab_char << std::endl;

    return 0;

}