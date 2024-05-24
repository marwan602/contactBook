//
// Created by Marwan Negm on 17/05/2024.
//

#ifndef UNTITLED6_PERSONDATABASE_H
#define UNTITLED6_PERSONDATABASE_H

#include <string>
#include "Person.h"
#include <fstream>
#include <vector>

class PersonDatabase {
public:
    void openDb(const std::string& dbName);
    std::vector<Person> getAllPeople();
    bool appendPerson(const Person& p);
    void deletePerson(const std::string& searchKey);
    bool findPerson(const std::string& searchKey);
    bool updatePerson(const std::string& searchKey);
    ~PersonDatabase();
private:
    void createDb(const std::string& dbName);
    std::fstream file;
    std::string dbName;
};


#endif //UNTITLED6_PERSONDATABASE_H
