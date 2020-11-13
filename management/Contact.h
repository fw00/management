

#ifndef MANAGEMENT_CONTACT_H
#define MANAGEMENT_CONTACT_H
#include <string>
#include <iostream>

//Here the contact.cpp is defined, the functions and variables that are from contact, with the constructor

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string number;
    std::string address;
public:
    Contact(std::string _first_name, std::string _last_name, std::string _number, std::string _address );
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNumber() const;
    std::string getAddress() const;
};


#endif //MANAGEMENT_CONTACT_H
