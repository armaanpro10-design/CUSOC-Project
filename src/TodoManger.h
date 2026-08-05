#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include "Task.h"
// We had included our main recipe of struct task into this file, to handle class more efficiently.
#include <vector>
// And tell me what's even more best than having a vector of task, i hope you maybe able to imagine an block of array pointing to it's different values, it;s like vector struct. hihih
#include <string>
// as usual string is always there to do basic operations. pheww..

// As Task should be handeled secretly, i mean there can be extreme task too, iykyk.
//Furthur to store we created a string of filename, for storage to be kept as secret too. hihihi
class TodoManager{
    private:
        std::vector<Task> tasks;
        //Here is our main recipe the main data structure.
        std::string filename;
        int nextId;
        void saveToFile();
        void loadFromFile();
    
        
    public:
        TodoManager(std::string file);
        // Now the question is why i had created this constructor? isn't it? 
        // That's because we have to get private values to access. we can use this constructor outside the class to initialize our desired private values.
        
        void addTask(std::string desc, std::string prio, std::string cat, std::string due);
        void listTasks();
        void markCompleted(int id);
        void deleteTask(int id);
        void editTask(int id, std::string nexDesc, std::string newPrio, std::string newCat, std::string newDue);

};

#endif