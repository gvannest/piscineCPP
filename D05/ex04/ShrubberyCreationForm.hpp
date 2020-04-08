#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {

    private:
        ShrubberyCreationForm(void);

    public:
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &  operator=(ShrubberyCreationForm const & rhs);

        void               action(void) const;


};

#endif