#include "span.hpp"
#include <algorithm>
#include <climits>
#include <iostream>

Span::Span(void){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(Span const & src){
    *this = src;
}

Span::~Span(void){}

unsigned int    Span::getN(void) const{
    return this->_N;
}

std::vector<int>    Span::getVec(void) const{
    return this->_vec;
}

Span &      Span::operator=(Span const & rhs){
    this->_N = rhs.getN();
    this->_vec = rhs.getVec();
    return *this;
}

void    Span::addNumber(int n){
    if ((this->_vec).size() == this->_N)
        throw std::length_error("object is full");
    else
        this->_vec.push_back(n);
}

long      Span::shortestSpan(void) const{
    if (this->_vec.size() < 2)
        throw std::logic_error("No span to calculate");
    std::vector<int> cpy = this->_vec;
    std::sort(cpy.begin(), cpy.end());
    std::vector<int>::const_iterator itE = cpy.end() - 1;
    long s = LONG_MAX;
    for (std::vector<int>::const_iterator itB = cpy.begin(); itB != itE; itB++){
        s = ((*(itB + 1) - *itB) < s ? (*(itB + 1) - *itB) : s);
    }
    return s;
}

long      Span::longestSpan(void) const{
    if (this->_vec.size() < 2)
        throw std::logic_error("No span to calculate");
    int max = *std::max_element(this->_vec.begin(), this->_vec.end());
    int min = *std::min_element(this->_vec.begin(), this->_vec.end());
    return (static_cast<long>(max - min));
}
