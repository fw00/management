//here the information of the contact is held
//the contact has different return functions to return its variables

#include "Contact.h"

Contact::Contact (std::string _first_name, std::string _last_name, std::string _number, std::string _address){
    first_name = _first_name;
    last_name = _last_name;
    number = _number;
    address = _address;
}

std::string Contact::getLastName() const{
    return  last_name;
}

std::string Contact::getFirstName() const{
    return first_name;
}

std::string Contact::getAddress() const{
    return address;
}

std::string Contact::getNumber() const{
    return number;
}