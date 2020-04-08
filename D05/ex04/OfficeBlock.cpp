#include "OfficeBlock.hpp"

OfficeBlock::
SomeoneMissingException::SomeoneMissingException(std::string const & message)
: _message(message)
{}

OfficeBlock::OfficeBlock(void){}
OfficeBlock::~OfficeBlock(void){}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signatory, Bureaucrat *executor)
: _intern(intern), _signatory(signatory), _executor(executor)
{}

OfficeBlock::OfficeBlock(OfficeBlock const & src){
    *this = src;
}

OfficeBlock &   OfficeBlock::operator=(OfficeBlock const & rhs){
    (void)rhs;
    return *this;
}

void    OfficeBlock::setIntern(Intern * intern){
    this->_intern = intern;
}   

void    OfficeBlock::setSignatory(Bureaucrat *signatory){
    this->_signatory = signatory;
}   

void    OfficeBlock::setExecutor(Bureaucrat *executor){
    this->_executor = executor;
}   


void            OfficeBlock::doBureaucracy(std::string form, std::string target) const{
    if (this->_intern == NULL || this->_signatory == NULL || this->_executor == NULL)
        throw SomeoneMissingException("Error: the Office block must contain 1 intern and 2 bureaucrats to do bureaucracy.");
    try {
        Form * new_form = this->_intern->makeForm(form, target);
        this->_signatory->signForm(*new_form);
        this->_executor->executeForm(*new_form);
    }
    catch (std::exception & e){
        throw;
    }
}
