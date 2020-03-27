#include "Human.hpp"
#include <iostream>

Human::Human(void){}

Human::~Human(void){}

void Human::meleeAttack(std::string const & target){
    std::cout << "Melee attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target){
    std::cout << "Ranged attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target){
    std::cout << "Intimidating shout on " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target){
    std::string actions_str[3] = {"meleeAttack", "rangeAttack", "intimidatingShout"};

    typedef void    (Human::*Action)(std::string const &);
    Action   actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

    for (int i = 0; i < 3; i++){
        if (actions_str[i] == action_name)
            (this->*actions[i])(target);
    }
}

