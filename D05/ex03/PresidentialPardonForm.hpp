#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {

    private:
        PresidentialPardonForm(void);

    public:
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm &  operator=(PresidentialPardonForm const & rhs);

        void               action(void) const;


};

#endif