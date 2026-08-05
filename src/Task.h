#ifndef TASK_H 
#define TASK_H //Macro

#include <string>

struct Task{
    int id;                 //Identifier of task
    std::string desc;       //description of task
    bool completed;         //Status flag
    std::string priority;   //priority level
    std::string category;   //category: work, personal, study
    std::string dueDate;    //Due date in simple string format(YYYY-MM-DD)
};

#endif

//struct is a user defined data type, just like in built int, float etc. Which mean we can use this to declare variable, And what could be even better than having a data type of task, i mean isn't it is best instead of handling each varible in class, we can just use task having all the properties of an task should have. That's the quite a reason i selected to use struct, (upto knowledge i have gained so far).