#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template< typename T >
class MutantStack : virtual public std::stack<T> {

    private:
        std::stack<T>             _stack;

    public:
        
        MutantStack(void) {}
        virtual ~MutantStack(void) {}

        // copy constructors
        MutantStack(MutantStack<T> const & src): std::stack<T>(src) {}
        MutantStack(std::stack<T> const & src): std::stack<T>(src) {}

        // container type is the underlying container object type.
        // 2nd template argument which by default is a deque
        // this underlying container has an iterator itself that we can use
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator    begin(void) { return std::stack<T>::c.begin(); }
        iterator    end(void) { return std::stack<T>::c.end(); }

};

#endif