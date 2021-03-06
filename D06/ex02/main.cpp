#include <iostream>

class Base {public: virtual ~Base(void){}};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void    identify_from_pointer(Base * p){
    A *   a = dynamic_cast<A *>(p);
    B *   b = dynamic_cast<B *>(p);
    C *   c = dynamic_cast<C *>(p);

    if (!a && !b && !c)
        std::cout << "Type not found among A, B and C" << std::endl;
    else if (!a && !b)
        std::cout << 'C' << std::endl;
    else if (!c && !b)
        std::cout << 'A' << std::endl;
    else if (!c && !a)
        std::cout << 'B' << std::endl;
}

void    identify_from_reference( Base & p ){
    try {
        A &   a = dynamic_cast<A &>(p);
        std::cout << 'A' << std::endl;
        (void)a;
    }
    catch (std::bad_cast & bca){
        try {
            B &   b = dynamic_cast<B &>(p);
            std::cout << 'B' << std::endl;
            (void)b;
        }
        catch (std::bad_cast & bcb) {
            try {
                C &   c = dynamic_cast<C &>(p);
                std::cout << 'C' << std::endl;
                (void)c;
            }
            catch (std::bad_cast & bcc) {
                std::cout << "Type not found among A, B and C" << std::endl;
            }
        }
    }
}

int main(void){
    Base *  p1 = new A;
    Base *  p2 = new B;
    Base *  p3 = new C;
    Base *  p4 = new Base;
    Base *  p5 = NULL;

    identify_from_pointer(p1);
    identify_from_pointer(p2);
    identify_from_pointer(p3);
    identify_from_pointer(p4);
    identify_from_pointer(p5);

    std::cout << "-----------------------" << std::endl;
    
    identify_from_reference(*p1);
    identify_from_reference(*p2);
    identify_from_reference(*p3);
    identify_from_reference(*p4);
}