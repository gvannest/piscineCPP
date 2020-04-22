#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

char const      Fixed::_fracBits = 8;

Fixed::Fixed(void) : _fixedPointValue(0) {
}

Fixed::Fixed(int const & n) {
    this->_fixedPointValue = n << Fixed::_fracBits;
}

Fixed::Fixed(float const & f) {
    this->_fixedPointValue = roundf(f * (1 << Fixed::_fracBits));
}

Fixed::Fixed(Fixed const & i) {
    *this = i;
}

Fixed::~Fixed(void) {
}

int         Fixed::getRawBits(void) const{
    return this->_fixedPointValue;
}

void        Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}

int         Fixed::toInt(void) const{
    return this->_fixedPointValue >> Fixed::_fracBits;
}

float       Fixed::toFloat(void) const{
    return (this->_fixedPointValue * 1.0) / (1 << Fixed::_fracBits);
}

Fixed &     Fixed::operator=(Fixed const & rhs){
    this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

bool        Fixed::operator>(Fixed const & rhs) const{
    return this->_fixedPointValue > rhs.getRawBits();
}

bool        Fixed::operator<(Fixed const & rhs) const{
    return this->_fixedPointValue < rhs.getRawBits();
}

bool        Fixed::operator>=(Fixed const & rhs) const{
    return this->_fixedPointValue >= rhs.getRawBits();
}

bool        Fixed::operator<=(Fixed const & rhs) const{
    return this->_fixedPointValue <= rhs.getRawBits();
}

bool        Fixed::operator==(Fixed const & rhs) const{
    return this->_fixedPointValue == rhs.getRawBits();
}

bool        Fixed::operator!=(Fixed const & rhs) const{
    return this->_fixedPointValue != rhs.getRawBits();
}

Fixed       Fixed::operator+(Fixed const & rhs){
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed       Fixed::operator-(Fixed const & rhs){
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed       Fixed::operator*(Fixed const & rhs){
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed       Fixed::operator/(Fixed const & rhs){
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &     Fixed::operator++(){
    ++this->_fixedPointValue;
    return *this;
}

Fixed       Fixed::operator++(int){
    Fixed unmodified = Fixed(*this);
    Fixed::operator++();
    return unmodified;
}   

Fixed &     Fixed::operator--(){
    --this->_fixedPointValue;
    return *this;
}

Fixed       Fixed::operator--(int){
    Fixed unmodified = Fixed(*this);
    Fixed::operator--();
    return unmodified;
}

Fixed &      Fixed::min(Fixed & i1, Fixed & i2){
    return (i1 < i2 ? i1 : i2);
}

Fixed const &      Fixed::min(Fixed const & i1, Fixed const & i2){
    return (i1 < i2 ? i1 : i2);
}

Fixed &      Fixed::max(Fixed & i1, Fixed & i2){
    return (i1 > i2 ? i1 : i2);
}

Fixed const &      Fixed::max(Fixed const & i1, Fixed const & i2){
    return (i1 > i2 ? i1 : i2);
}

std::ostream &      operator<<(std::ostream & o, Fixed const & i){
    o << i.toFloat();
    return o;
}