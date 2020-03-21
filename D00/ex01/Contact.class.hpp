#ifndef CONTACT_HPP
# define CONTACT_HPP

// # include <string>
# include <iostream>

class Contact {

    private:
        int         _index;
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _login;
        std::string _postal_address;
        std::string _email_address;
        std::string _phone_number;
        std::string _birthday_date;
        std::string _favorite_meal;
        std::string _underwear_color;
        std::string _darkest_secret;
    
    public:
        Contact(void);      //Constructor
        ~Contact(void);     // Destructor

        int         get_index(void){
            return this->_index;
        }
        
        std::string get_firstname(void){
            return this->_firstname;
        }

        void set_firstname(std::string firstname){
            this->_firstname = firstname;
        }

        std::string get_lastname(void){
            return this->_lastname;
        }

        void set_lastname(std::string lastname){
            this->_lastname = lastname;
        }

        std::string get_nickname(void){
            return this->_nickname;
        }

        void set_nickname(std::string nickname){
            this->_nickname = nickname;
        }

        std::string get_login(void){
            return this->_login;
        }

        void set_login(std::string login){
            this->_login = login;
        }

        std::string get_postal_address(void){
            return this->_postal_address;
        }

        void set_postal_address(std::string postal_address){
            this->_postal_address = postal_address;
        }

        std::string get_email_address(void){
            return this->_email_address;
        }

        void set_email_address(std::string email_address){
            this->_email_address = email_address;
        }

        std::string get_phone_number(void){
            return this->_phone_number;
        }

        void set_phone_number(std::string phone_number){
            this->_phone_number = phone_number;
        }

        std::string get_birthday_date(void){
            return this->_birthday_date;
        }

        void set_birthday_date(std::string birthday_date){
            this->_birthday_date = birthday_date;
        }

        std::string get_favorite_meal(void){
            return this->_favorite_meal;
        }

        void set_favorite_meal(std::string favorite_meal){
            this->_favorite_meal = favorite_meal;
        }

        std::string get_underwear_color(void){
            return this->_underwear_color;
        }

        void set_underwear_color(std::string underwear_color){
            this->_underwear_color = underwear_color;
        }

        std::string get_darkest_secret(void){
            return this->_darkest_secret;
        }

        void set_darkest_secret(std::string darkest_secret){
            this->_darkest_secret = darkest_secret;
        }
};


#endif