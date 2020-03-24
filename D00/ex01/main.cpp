# include "Contact.class.hpp"
# include <iomanip>
# include "botin.h"

t_botin botin[11] = {
            {"first name", &Contact::get_firstname},
            {"last name", &Contact::get_lastname},
            {"nickname", &Contact::get_nickname},
            {"login", &Contact::get_login},
            {"postal address", &Contact::get_postal_address},
            {"email address", &Contact::get_email_address},
            {"phone number", &Contact::get_phone_number},
            {"birthday date", &Contact::get_birthday_date},
            {"favorite meal", &Contact::get_favorite_meal},
            {"underwear color", &Contact::get_underwear_color},
            {"darkest secret", &Contact::get_darkest_secret},
        };

void    print_string_fields(std::string str, size_t width){
    if (str.length() > width)
        std::cout << std::setw(width) << str.substr(0, width - 1) << ".|";  
    else
        std::cout << std::setw(width) << str << '|';  
}

int     main(void){

    std::string     input;
    int             len;
    int             idx = 1;
    std::string     fields[3] = {"first name", "last name", "login"};

    while (1){
        std::cout << "Please enter a command : "; 
        std::getline(std::cin, input);;
        if (!input.compare("EXIT"))
            return 0;
        else if (!input.compare("ADD")){
            std::string     data[11];
            for (int i = 0; i < 11; i++){
                std::cout << "Please enter " << botin[i].str << " : ";
                std::getline(std::cin, data[i]); //Note: data[i] ici contient une string = c'est un pointeur vers string
            }
            Contact new_contact(idx, data);
            std::cout << &new_contact << std::endl;
            Contact::insert_contact(idx, &new_contact);
            if (idx == 2){
                Contact *contact_1 = Contact::get_contact(1);
                Contact *contact_2 = Contact::get_contact(2);
                std::cout << contact_1 << std::endl;
                std::cout << contact_1->get_index() << std::endl;
                std::cout << contact_2 << std::endl;
                std::cout << contact_2->get_index() << std::endl;
            }
            // ATTENTION GERER DANS LA FONCTION MEMBRE LE COMPORTEMENT SI > 8 contacts!!
            // NOTAMMENT QUEL COMPORTEMENT EN FONCTION DE L'INDEX??
            idx++;
        }        
        else if (!input.compare("SEARCH")){
            // printer des titres de colonnes
            len = Contact::contact_list_size();
            for (int x = 0; x < len; x++){
                Contact *current_contact = Contact::get_contact(x + 1);
                std::cout << std::setw(10) << current_contact->get_index() << '|';
                for (int y = 0; y < 3; y++){
                    for (int z = 0; z < 11; z++){
                        if (!fields[y].compare(botin[z].str)){
                            print_string_fields((current_contact->*(botin[z].f))(), 10);
                            break;
                        }
                    }
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}