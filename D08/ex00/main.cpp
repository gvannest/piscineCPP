#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct RandomGenerator {
	int maxValue;
	RandomGenerator(int max) :
			maxValue(max) {
	}
 
	int operator()() {
		return rand() % maxValue;
	}
};

void    displayInt(int i){
    std::cout << i << ' ';
}

int main(void){
    srand(time(NULL));
    
    std::vector<int> intVector(15);
    std::generate(intVector.begin(), intVector.end(), RandomGenerator(20));

    std::list<int> intList(15, 0);
    std::generate(intList.begin(), intList.end(), RandomGenerator(20));

    std::vector<int> intVector2(15);
    std::generate(intVector2.begin(), intVector2.end(), RandomGenerator(20));
    std::set<int> intSet(intVector2.begin(), intVector2.end());

    for_each(intVector.begin(), intVector.end(), displayInt);
    std::cout << std::endl;
    for_each(intList.begin(), intList.end(), displayInt);
    std::cout << std::endl;
    for_each(intSet.begin(), intSet.end(), displayInt);
    std::cout << std::endl;
    std::cout << "-----------------" << std::endl;

    for (std::set<int>::iterator it = intSet.begin(); it != intSet.end(); ++it){
        try {
            std::vector<int>::iterator p = easyfind< std::vector<int> >(intVector, *it);
            std::cout << "First " << *it << " in intVector is at address " << std::addressof(*p) << std::endl;
        }
        catch (ValueNotFoundException & e){
            std::cout << e.what() << std::endl;
        }
        try {
            std::list<int>::iterator itL = easyfind< std::list<int> >(intList, *it);
            std::cout << "First " << *it << " in intList is at address " << std::addressof(*itL) << std::endl;
        }
        catch (ValueNotFoundException & e){
            std::cout << e.what() << std::endl;
        }
        try {
            std::set<int>::iterator itS = easyfind< std::set<int> >(intSet, *it);
            std::cout << "First " << *it << " in intSet is at address " << std::addressof(*itS) << std::endl;
        }
        catch (ValueNotFoundException & e){
            std::cout << e.what() << std::endl;
        }
    }

    return 0;


}