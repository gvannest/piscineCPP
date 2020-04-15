#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <string>
# include <sstream>

class ValueNotFoundException : public std::exception {
    public:
        ValueNotFoundException(std::string msg): _msg(msg){
        }
        virtual ~ValueNotFoundException(void) _NOEXCEPT {}
        virtual const char * what() const throw(){
            return this->_msg.c_str();
        }

    private:
        std::string     _msg;
        ValueNotFoundException(void);
};

template< typename T >
typename T::iterator    easyfind(T & intContainer, int x){
    typename T::iterator it;
    it = std::find(intContainer.begin(), intContainer.end(), x);
    if (it == intContainer.end()){
        std::ostringstream  oss;
        oss << x << " has not been found in the container";
        throw ValueNotFoundException(oss.str());
    }
    else
        return it;
}


#endif