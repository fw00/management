//
// This file handles all tasks for the contactlist
// The user can add search or delete a contact from their list
// The list is saved in a file and edited (contacts.txt)
//

#include "ContactList.h"
#include "Contact.h"
#include <vector>

bool length(const std::string&);
void addContact();
void getContact();
void deleteContact();
void update();
std::vector <Contact> contacts;

//asks the user what they want to choose to do with their contact list
void ContactList::question(){
    int choice;
    std::cout << "Contact List" << std::endl;
    std::cout << "1. Add Contact" << std::endl << "2. Search Contact" << std::endl << "3. Delete contact" << std::endl << "4. Exit " << std::endl;
    std::cin >> choice;
    //based on the choice, go to the correct function
    if (choice == 1){
        addContact();
    } else if ( choice == 2){
        getContact();
    } else if ( choice == 3) {
        deleteContact();
    }else if ( choice == 4) {
    }else {
        std::cout << "Invalid Input !";
        ContactList::question();
    }
    std::cout << "Do you want to do something else with the contact list? Y/N" << std::endl;
    std::string more;
    std::cin >> more;
    //run this function again if the user wants to continue editing/looking
    if (more =="Y" || more =="y"){
        question();
    }else if (more =="N" || more =="n"){

    }else{
        std::cout << "invalid input" << std::endl;
    }
}

void addContact(){
    std::string first_name;
    std::string last_name;
    std::string number;
    std::string address;
    //user input to determine the contact variables
    std::cout << "First Name : ";
    std::cin >> first_name;
    std::cout << "Last Name : ";
    std::cin >> last_name;
    std::cout << "Phone Number : ";
    std::cin >> number;
    std::cout << "Address: ";
    std::cin >> address;
    contacts.emplace_back(Contact(first_name, last_name, number, address));
    std::ofstream fileOut("contacts.txt" , std::ios::app);
    // if valid input the information of the contact is saved in the file
    if(length(number)){
        std::ifstream fileIn ("contacts.txt");
        if(fileIn.is_open()){
                fileOut << contacts.back().getFirstName() << " " << contacts.back().getLastName() << " " << contacts.back().getNumber() << " " << contacts.back().getAddress() << std::endl;
                std::cout << "Contact is saved" << std::endl;
        }else{
            std::cout << "Cannot open file" << std::endl;
        }
    }else{
            std::cout << "Enter a a phone number with 11 numbers" << std::endl;
        }
    fileOut.close();
}

void getContact(){
    std::string first_name;
    std::string last_name;
    std::string number;
    std::string address;

    bool find = false;
    std::ifstream fileIn("contacts.txt");
    std::string search;
    std::cout << "Search for:";
    std::cin >> search;
    //Check if the name corresponds to a name in the file, then print
    while(fileIn >> first_name >> last_name >> number >> address){
        if(search == first_name || search == last_name){
            std::cout << "Contact info:" << std::endl;
            std::cout << "First Name: " << first_name << std::endl;
            std::cout << "Last Name: " << last_name << std::endl;
            std::cout << "Phone Number: " << number << std::endl;
            std::cout << "Address: " << address << std::endl;
            find = true;
        }
    }
    if(!find){
        std::cout << "no results";
    }

}

void deleteContact() {
    // replace the found contact by empty strings --> thus deleting the contact
    std::string first_name;
    std::string last_name;
    std::string number;
    std::string address;
    std::ifstream fileIn("contacts.txt");
    std::string search;
    std::cout << "Search for:";
    std::cin >> search;
    bool found = false;
    while (fileIn >> first_name >> last_name >> number >> address) {
        if (search == first_name || search == last_name) {
            found = true;
            first_name = " ";
            last_name = " ";
            number = " ";
            address = " ";
            //change the vector based on which contact needs to be deleted
            for (int i = 0; i < contacts.size(); i++) {
                if (contacts.at(i).getFirstName() == search || contacts.at(i).getLastName() == search) {
                    Contact contact(contacts.at(i).getFirstName(), contacts.at(i).getLastName(),
                                    contacts.at(i).getNumber(), contacts.at(i).getAddress());
                    contacts.erase(contacts.begin() + i);
                }
            }
            std::ofstream fileOut("contacts.txt");
            //write the empty strings to the file
            if (fileIn.is_open()) {
                fileOut << first_name << last_name << number << address << std::endl;
                std::cout << "Contact has been deleted" << std::endl;
            } else {
                std::cout << "Cannot open file" << std::endl;
            }
            fileOut.close();
            //write the vector to the file
            update();
        }
        if (!found) {
            std::cout << "no results";
        }
    }
}

bool length(const std::string& x){
    //check if the phonenumber has a length of 11
    if(x.length() == 11)
        return true;
    else
        return false;
}

void update(){
    //update the text file after deleting contacts
    std::ofstream fileOut("contacts.txt" , std::ios::app);
    for (int i = 0; i < contacts.size(); i++) {
        std::ifstream fileIn ("contacts.txt");
        if(fileIn.is_open()){
            fileOut << contacts.back().getFirstName() << " " << contacts.back().getLastName() << " " << contacts.back().getNumber() << " " << contacts.back().getAddress() << std::endl;
            std::cout << "Updated!" << std::endl;
        }else{
            std::cout << "Cannot open file" << std::endl;
        }
    }
    fileOut.close();
}

