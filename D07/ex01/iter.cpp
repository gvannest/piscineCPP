#include <iostream>
#include <cstdlib>

#include "Test.class.hpp"

template <typename T>
void iter(T *tab, size_t size, void (*f)(T &))
{
    for (size_t i = 0; i < size; i++)
        (*f)(tab[i]);
}

template <typename T>
void square(T & a)
{
    a *= a;
}

template <typename U>
void add_one(U &u)
{
    u += 1;
}

int main(void)
{
    char tab_char[] = "Hello World!";
    int tab[8] = {3, 5, -2, 8, 1, 10, 7, -5};

    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;
    iter<int>(tab, 8, &square);
    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;
    iter<int>(tab, 8, add_one);
    for (int i = 0; i < 8; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;

    std::cout << tab_char << std::endl;
    iter<char>(tab_char, 12, &add_one);
    std::cout << tab_char << std::endl;

    std::cout << "------------------------" << std::endl;

    int tab1[] = { 0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter(tab1, 5, print);
    iter( tab2, 5, print);

    return 0;
}