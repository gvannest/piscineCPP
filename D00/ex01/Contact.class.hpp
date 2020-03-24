#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
// # include "botin.h"

class Contact {
    
    private:
        int             _index;
        std::string     _params[11];
        static Contact  *_contact_list[9];
    
    public:

        Contact(int idx, std::string p[11]);        //Constructor
        ~Contact(void);                             // Destructor

        static void     insert_contact(int idx, Contact *contact);
        static Contact  *get_contact(int idx);
        static int      contact_list_size(void);
        void            ft_copy_data(std::string data[11]);

        int             get_index(void) const; 

        std::string     get_firstname(void) const;
        void            set_firstname(std::string firstname);

        std::string     get_lastname(void) const;
        void            set_lastname(std::string lastname);

        std::string     get_nickname(void) const;
        void            set_nickname(std::string nickname);

        std::string     get_login(void) const;
        void            set_login(std::string login);

        std::string     get_postal_address(void) const;
        void            set_postal_address(std::string postal_address);

        std::string     get_email_address(void) const;
        void            set_email_address(std::string email_address);

        std::string     get_phone_number(void) const;
        void            set_phone_number(std::string phone_number);

        std::string     get_birthday_date(void) const;
        void            set_birthday_date(std::string birthday_date);

        std::string     get_favorite_meal(void) const;
        void            set_favorite_meal(std::string favorite_meal);

        std::string     get_underwear_color(void) const;
        void            set_underwear_color(std::string underwear_color);

        std::string     get_darkest_secret(void) const;
        void            set_darkest_secret(std::string darkest_secret);

};


#endif