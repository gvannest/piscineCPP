#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <string>
# include <exception>
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock {
    
    private:
        Intern *         _intern;
        Bureaucrat *     _signatory;
        Bureaucrat *     _executor;

        OfficeBlock(OfficeBlock const & src);
        OfficeBlock & operator=(OfficeBlock const & rhs);

    public:
        OfficeBlock(void);
        OfficeBlock(Intern *, Bureaucrat *, Bureaucrat *); //pointers because can be null
        virtual ~OfficeBlock(void);

        void    setIntern(Intern *);    
        void    setSignatory(Bureaucrat *);    
        void    setExecutor(Bureaucrat *);    

        void    doBureaucracy(std::string form, std::string target) const;

        class SomeoneMissingException : public std::exception {
            private:
                std::string     _message;
            
            public:
                SomeoneMissingException(void){};
                SomeoneMissingException(std::string const & message);
                virtual ~SomeoneMissingException(void) _NOEXCEPT{};
                virtual const char * what() const throw(){
                    return _message.c_str();
                }
        };

};

#endif