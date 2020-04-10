#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstdlib>
# include <iostream>
# include <exception>

template< typename T >
class Array {

    public:
        Array<T>(void);
        Array<T>(unsigned int n);
        Array<T>(Array<T> const & src);
        virtual ~Array<T>(void);

        Array<T> &  operator=(Array<T> const & rhs);
        T &         operator[](size_t const);

        T *         getArray(void) const;
        size_t      size(void) const;

    private:
        T *     _array;
        size_t  _size;

    class outOfBoundException : public std::exception {
        const char * what() const throw() {
            return "Error: trying to access out of bound memory.";
        }
    };
};

template< typename T >
std::ostream &      operator<<(std::ostream & o, Array<T> const & rhs){
    T * ptr = rhs.getArray();
    if (ptr == NULL)
        return o;
    o << "{ ";
    for (size_t i = 0; i < rhs.size(); i++)
        o << ptr[i] << " , ";
    o << " }";
    return o;
}


template< typename T >
Array<T>::Array(void) : _size(0) {
    this->_array = new T[0];
}

template< typename T >
Array<T>::Array(unsigned int n) : _size(n) {
    this->_array = new T[n]();
}

template< typename T >
Array<T>::Array(Array<T> const & src) {
    *this = src;
}

template< typename T >
Array<T>::~Array(void) {
    delete [] this->_array;
}

template< typename T >
Array<T> &  Array<T>::operator=(Array<T> const & rhs){
    T * rhs_array = rhs.getArray();
    if (rhs_array == NULL){
        this->_array = 0;
        this->_size = 0;
    }
    else {
        T * new_array = new T[rhs.size()];
        for (size_t i = 0; i < rhs.size(); i++)
            new_array[i] = rhs_array[i];
        this->_array = new_array;
        this->_size = rhs.size();
    }
    return *this;
}

template< typename T >
T &     Array<T>::operator[](size_t const idx){
    if (idx >= this->_size)
        throw outOfBoundException();
    else
        return *(this->_array + idx);
}

template< typename T >
T *     Array<T>::getArray(void) const{
    return this->_array;
}

template< typename T >
size_t     Array<T>::size(void) const{
    return this->_size;
}


#endif