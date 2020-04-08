#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {

    private:
        RobotomyRequestForm(void);

    public:
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm &  operator=(RobotomyRequestForm const & rhs);

        void               action(void) const;


};

#endif