#ifndef TASK_H
#define TASK_H

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