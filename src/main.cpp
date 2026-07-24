#include <iostream>
#include <string>
#include "TodoManger.h"

int getinput(){
    int choice;
    std::cin >> choice;

    std::cin.ignore(10000, '\n');
    return choice;
}

int main(){

    TodoManager manager("tasks.txt");

    while(true){

        std::cout << "\n=== CLI Todo App\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. List Tasks\n";
        std::cout << "3. Mark Completed\n";
        std::cout << "4. Edit Tasks\n";
        std::cout << "5. Delete Task\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";

        int choice = getinput();

        if(choice == 1){
            std::string desc, prio, cat , due;

            std::cout << "Description: ";
            std::getline(std::cin, desc);

            std::cout << "Priority (High, Medium, Low): ";
            std::getline(std::cin, prio);
            
            std::cout << "Category (Work/Personal/Study): ";
            std::getline(std::cin, cat);

            std::cout << "Due Date(YYYY-MM-DD): ";
            std::getline(std::cin, due);

            manager.addTask(desc, prio, cat, due);
        }
    }
}