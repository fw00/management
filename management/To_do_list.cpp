//
// Here a to do list can be created
// the main functionalities are to add a task, find tasks based on date and find tasks based on their priority level
//

#include "To_do_list.h"

std::string task;
int level;
const int size = 3;
int date[size];
void addTask();
void getDate();
void getLevel();
bool digits(const int[]);

//the "main" of the class, here the user is asked what to do with the to do list, and after that if the user wants to do more
void To_do_list::question(){
    int choice;
    std::cout << "To do List" << std::endl;
    std::cout << "1. Add Task" << std::endl << "2. Review task of specific date" << std::endl << "3. Review task of specific level" << std::endl << "4. Exit " << std::endl;
    std::cin >> choice;
    if (choice == 1){
        addTask();
    } else if ( choice == 2){
        getDate();
    } else if ( choice == 3) {
        getLevel();
    }else if ( choice == 4) {
    }else {
        std::cout << "Invalid Input !";
        To_do_list::question();
    }
    std::cout << "Do you want to do something else with the to do list? Y/N" << std::endl;
    std::string more;
    std::cin >> more;
    if (more =="Y" || more =="y"){
        question();
    }else if (more =="N" || more =="n"){

    }else{
        std::cout << "invalid input" << std::endl;
    }
}

void addTask(){
    std::ofstream fileOut("tdl.txt" , std::ios::app);
    std::cout << "Task: ";
    std::cin >> task;
    std::cout << "Level (1 through 5) ";
    std::cin >> level;
    std::cout << "day:";
    std::cin >> date[0];
    std::cout << "month:";
    std::cin >> date[1];
    std::cout << "year:";
    std::cin >> date[2];
    // the user input it written to the file when the date is valid
    if(digits(date)){
        std::ifstream fileIn ("tdl.txt");
        if(fileIn.is_open()){
            fileOut << task << " " << level << " " ;
            for(int i : date){
                fileOut << i << " ";
            }
            fileOut << std::endl;
            std::cout << "Task is saved" << std::endl;
        }else{
            std::cout << "Cannot open file" << std::endl;
        }}else{
        std::cout << "Enter a date with the days between 1-31, month between 1-12 and year after 2020" << std::endl;
    }
    fileOut.close();
}
bool digits(const int _date[]){
    //check for valid date
    if((_date[0] >= 1 && _date[0]<= 31) && (_date[1] >= 1 && _date[1]<= 12) && (_date[2] >= 2020))
        return true;
    else
        return false;
}

void getDate() {
    //print the task for a specific date
    std::ifstream fileIn("tdl.txt");
    int day, month, year;
    int _day, _month, _year;
    std::cout << "Search for day:";
    std::cin >> _day;
    std::cout << "Search for month:";
    std::cin >> _month;
    std::cout << "Search for year:";
    std::cin >> _year;
    while (fileIn >> task >> level >> day >> month >> year) {
        if(day == _day && month == _month && year == _year){
            std::cout << "Task info:" << std::endl;
            std::cout << "Task name: " << task << std::endl;
            std::cout << "level: " << level << std::endl;
            std::cout << "Date: " << day << " " << month << " " << year << std::endl;
            break;
        }
    }
}

void getLevel(){
    // get the to do for a level of priority
    std::ifstream fileIn("tdl.txt");
    std::cout << "Search for level of priority:";
    int search;
    std::cin >> search;
    int day, month, year;
    while (fileIn >> task >> level >> day>> month >> year ) {
        std::cout << level << std::endl;
        if(search == level){
            std::cout << "Task info:" << std::endl;
            std::cout << "Task name: " << task << std::endl;
            std::cout << "level: " << level << std::endl;
            break;
        }
    }
}