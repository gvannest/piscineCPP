#include "Contact.class.hpp"

Contact::Contact(int idx, std::string p[11]) : _index(idx) {
    for (int i = 0; i < 11; i++){
        this->_params[i] = p[i];
        std::cout << this->_params[i] << std::endl;
    }
    return;
}

Contact::~Contact(void){
    return;
}

void        Contact::insert_contact(int idx, Contact *contact){
    if (idx < 9 && idx > 0)
        Contact::_contact_list[idx - 1] = contact;
    else
        std::cout << "There was an error on the insertion of the contact" << std::endl;
    return;
}

Contact     *Contact::get_contact(int idx){
    if (idx < 9 && idx > 0)
        return Contact::_contact_list[idx - 1];
    else
        std::cout << "Error: index out of range" << std::endl;
    return 0;
}

int         Contact::contact_list_size(void){
    int i = 0;
    while (Contact::_contact_list[i])
        i++;
    return i;
}

int         Contact::get_index(void) const{
    return this->_index;
}

std::string Contact::get_firstname(void) const{
    return this->_params[0];
}

void        Contact::set_firstname(std::string firstname){
    this->_params[0] = firstname;
}

std::string Contact::get_lastname(void) const{
    return this->_params[1];
}

void        Contact::set_lastname(std::string lastname){
    this->_params[1] = lastname;
}

std::string Contact::get_nickname(void) const{
    return this->_params[2];
}

void        Contact::set_nickname(std::string nickname){
    this->_params[2] = nickname;
}

std::string Contact::get_login(void) const{
    return this->_params[3];
}

void        Contact::set_login(std::string login){
    this->_params[3] = login;
}

std::string Contact::get_postal_address(void) const{
    return this->_params[4];
}

void        Contact::set_postal_address(std::string postal_address){
    this->_params[4] = postal_address;
}

std::string Contact::get_email_address(void) const{
    return this->_params[5];
}

void        Contact::set_email_address(std::string email_address){
    this->_params[5] = email_address;
}

std::string Contact::get_phone_number(void) const{
    return this->_params[6];
}

void        Contact::set_phone_number(std::string phone_number){
    this->_params[6] = phone_number;
}

std::string Contact::get_birthday_date(void) const{
    return this->_params[7];
}

void        Contact::set_birthday_date(std::string birthday_date){
    this->_params[7] = birthday_date;
}

std::string Contact::get_favorite_meal(void) const{
    return this->_params[8];
}

void        Contact::set_favorite_meal(std::string favorite_meal){
    this->_params[8] = favorite_meal;
}

std::string Contact::get_underwear_color(void) const{
    return this->_params[9];
}

void        Contact::set_underwear_color(std::string underwear_color){
    this->_params[9] = underwear_color;
}

std::string Contact::get_darkest_secret(void) const{
    return this->_params[10];
}

void        Contact::set_darkest_secret(std::string darkest_secret){
    this->_params[10] = darkest_secret;
}

Contact *Contact::_contact_list[9] = {0};