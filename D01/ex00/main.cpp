#include "Pony.hpp"
#include <iostream>

static void    ponyOnTheStack(void){
    std::cout << "I am getting into the ponyOnTheStack function" << std::endl;
    Pony    myPonyStack = Pony("Stack Pony", 12);
    std::cout << myPonyStack.make_sound() << std::endl;
    std::cout << "I am getting out of the ponyOnTheStack function" << std::endl;
    return;
}

static void    ponyOnTheHeap(void){
    std::cout << "I am getting into the ponyOnTheHeap function" << std::endl;
    Pony    *myPonyHeap = new Pony("Heap Pony", 2);
    std::cout << myPonyHeap->make_sound() << std::endl;
    delete myPonyHeap;
    std::cout << "I am getting out of the ponyOnTheHeap function" << std::endl;
    return;
}

int     main(void){
    ponyOnTheStack();
    ponyOnTheHeap();
    return (0);
}