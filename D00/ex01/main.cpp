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
        std::cout << std::setw(width) << str.substr(0, width - 1) + '.' << '|';  
    else
        std::cout << std::setw(width) << str << '|';  
}



void    ft_add(){
    int             len;
    int             choice;
    static int      idx = 1;
    std::string     data[11];
    len = Contact::contact_list_size();
    if (len == 8){
        std::cout << "There is no space left in the botin." << std::endl;
        std::cout << "Please type an index to be replaced or '0' to cancel : ";
        while (!(std::cin >> choice) || choice < 0 || choice > len){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong answer please provide a valid number" << std::endl;
            std::cout << "Please type an index to be replaced or '0' to cancel : ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!choice)
            return;
        idx = choice;
    }
    for (int i = 0; i < 11; i++){
        std::cout << "Please enter " << botin[i].str << " : ";
        std::getline(std::cin, data[i]);
    }
    Contact *current_contact = Contact::get_contact(idx);
    current_contact->ft_copy_data(data);
    idx++;
}

void    ft_search(){
    int             len;
    std::string     fields[3] = {"first name", "last name", "login"};

    std::cout << std::setw(10) << "Index" << '|';
    for (int i= 0; i < 3; i++){
        print_string_fields(fields[i], 10);
    }
    std::cout << std::endl;

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
    int      choice; 
    std::cout << "Please choose a contact index : "; 
    while (!(std::cin >> choice) || choice < 1 || choice > len){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong answer please provide a valid number" << std::endl;
        std::cout << "Please choose a contact index : "; 
    }
    Contact *current_contact = Contact::get_contact(choice);
    for (int i = 0; i < 11; i++){
        std::cout << botin[i].str << " : ";
        std::cout << (current_contact->*(botin[i].f))() << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int     main(void){

    std::string     input;
    std::string    data_init[11] = {"", "", "", "", "", "", "", "", "", "", ""};

    Contact contact1(1, data_init);
    Contact contact2(2, data_init);
    Contact contact3(3, data_init);
    Contact contact4(4, data_init);
    Contact contact5(5, data_init);
    Contact contact6(6, data_init);
    Contact contact7(7, data_init);
    Contact contact8(8, data_init);

    Contact::insert_contact(1, &contact1);
    Contact::insert_contact(2, &contact2);
    Contact::insert_contact(3, &contact3);
    Contact::insert_contact(4, &contact4);
    Contact::insert_contact(5, &contact5);
    Contact::insert_contact(6, &contact6);
    Contact::insert_contact(7, &contact7);
    Contact::insert_contact(8, &contact8);

    while (1){
        std::cout << "Please enter a command : "; 
        std::getline(std::cin, input);;
        if (!input.compare("EXIT"))
            return 0;
        else if (!input.compare("ADD"))
            ft_add();
        else if (!input.compare("SEARCH"))
            ft_search();
    }
    return 0;
}