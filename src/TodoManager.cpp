#include "TodoManger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

TodoManager::TodoManager(std::string file){
    filename = file;
    nextId = 1;
    loadFromFile();
}

void TodoManager::loadFromFile(){
    std::ifstream file(filename);
    if(!file.is_open()) return;

    std::string line;

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string item;
        Task t;

        std::getline(ss, item, ','); t.id = std::stoi(item);
        std::getline(ss, t.desc, ',');
        std::getline(ss, item, ','); t.completed = (item == "1");
        std::getline(ss, t.priority, ',');
        std::getline(ss, t.category, ',');
        std::getline(ss, t.dueDate, ',');

        tasks.push_back(t);

        if(t.id >= nextId) nextId = t.id +1;
    }
    file.close();
}

void TodoManager::saveToFile(){
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cout << "Error Opening file for saving!\n";
        return;
    }

    for(const auto& t : tasks){

        file << t.id << "," << t.desc << "," << (t.completed ? "1" : "0") << "," << t.priority << "," << t.category << "," << t.dueDate << "\n";
    }

    file.close();
}

void TodoManager::addTask(std::string desc, std::string prio, std::string cat, std::string due){

    Task newTask;
    newTask.id = nextId++;
    newTask.desc = desc;
    newTask.completed = false;
    newTask.priority = prio;
    newTask.category = cat;
    newTask.dueDate = due;

    tasks.push_back(newTask);
    saveToFile();
    std::cout << "Task added successfully with ID: " << newTask.id << "\n";
}

void TodoManager::listTasks(){
    if(tasks.empty()){
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << std::left << std::setw(5) << "ID" << std::setw(10) << "Status" << std::setw(15) << "Priority" << std::setw(15) << "category" << std::setw(15) << "Due Date" << "Description\n";

    std::cout << std::string(80, '-') << "\n";

    for(const auto& t : tasks){
        std::string status = t.completed ? "[Done]" : "[]";

        std::cout << std::left << std::setw(5) << t.id << std::setw(10) << status << std::setw(15) << t.priority << std::setw(15) << t.category << std::setw(15) << t.dueDate << t.desc << "\n"; 
    }
}

void TodoManager::markCompleted(int id){

    for(auto& t : tasks){
        if(t.id == id){
            t.completed = true;
            saveToFile();
            std::cout << "Task " << id << " marked as completed.\n";
            return;
        }
    }
    std::cout << "Task ID not found.\n";
}

void TodoManager::deleteTask(int id){
    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        if(it->id == id){
            tasks.erase(it);
            saveToFile();
            std::cout << "Task " << id << " deleted.\n";
            return;
        }
    }
    std::cout << "Task ID not found.\n";
}

void TodoManager::editTask(int id, std::string newDesc, std::string newPrio, std::string newCat, std::string newDue){

    for(auto& t : tasks){
        if(t.id == id){
            t.desc = newDesc;
            t.priority = newPrio;
            t.category = newCat;
            t.dueDate = newDue;
            saveToFile();
            std::cout << "Task " << id << " updated.\n";
            return;
        }
    }
    std::cout << "Task ID not found.\n";
}