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