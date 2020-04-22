#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

char const      Fixed::_fracBits = 8;

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const & n) {
    std::cout << "Parameter int constructor called" << std::endl;
    this->_fixedPointValue = n << Fixed::_fracBits;
}

Fixed::Fixed(float const & f) {
    std::cout << "Parameter float constructor called" << std::endl;
    this->_fixedPointValue = roundf(f * (1 << Fixed::_fracBits));
}

Fixed::Fixed(Fixed const & i) {
    std::cout << "Copy constructor called" << std::endl;
    *this = i;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed &     Fixed::operator=(Fixed const & rhs){
    std::cout << "Assignation operator called" << std::endl;
    this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

int         Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void        Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

int         Fixed::toInt(void) const{
    return this->_fixedPointValue >> Fixed::_fracBits;
}

float       Fixed::toFloat(void) const{
    return (this->_fixedPointValue * 1.0) / (1 << Fixed::_fracBits);
}

std::ostream &      operator<<(std::ostream & o, Fixed const & i){
    o << i.toFloat();
    return o;
}