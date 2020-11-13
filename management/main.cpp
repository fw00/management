// Programming in Engineering, 11-11-2020, University of Twente
// Yujia Kong s2235617 & Feline Waardenburg s2157993
// this program is a managament system giving you a contact list and to do list to edit to desire and view

#include <iostream>
#include "ContactList.h"
#include "To_do_list.h"

int main(){
    int input;
    //menu of the management system, using switch to switch between states
    do {
        std::cout << "Please choose if you want to use your contact list or to_do_list" << std::endl;
        std::cout << "1. Contact list" <<std::endl << "2. To do list" << std::endl << "3. Exit" << std::endl;
        std::cin >> input;
        switch(input){
            case 1:
                ContactList::question();
                break;
            case 2:
                To_do_list::question();
                break;
            case 3:
                std::cout << "Goodbye!" ;
                return 0;
            default:
                std::cout << "Invalid input";
        }
    }
    while(input != 3);
}











