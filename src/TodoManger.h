#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include "Task.h"
#include <vector>
#include <string>

class TodoManager{
    private:
        std::vector<Task> tasks;
        std::string filename;
        int nextId;
        void saveToFile();
        void loadFromFile();
    
        
    public:
        TodoManager(std::string file);
        
        void addTask(std::string desc, std::string prio, std::string cat, std::string due);
        void listTasks();
        void markCompleted(int id);
        void deleteTask(int id);
        void editTask(int id, std::string nexDesc, std::string newPrio, std::string newCat, std::string newDue);

};

#endif