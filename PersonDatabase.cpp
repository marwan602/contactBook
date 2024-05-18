//
// Created by Marwan Negm on 17/05/2024.
//

#include "PersonDatabase.h"
#include "PersonSerializer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

const int EMPTYJSON = 15;

bool fileExists(const std::string& dbName) {
    std::ifstream ifile;
    ifile.open(dbName + ".json");
    return (bool) ifile;
}

void PersonDatabase::openDb(const std::string& dbName) {
    if (fileExists(dbName)) {
        file.open(dbName + ".json");
        std::cout << "File found! Opening file...\n";
        return;
    }
    std::cout << "File not found! Creating a new database...\n";
    createDb(dbName);
}

void PersonDatabase::createDb(const std::string& dbName) {
    file.open(dbName + ".json", std::ios::out);
    std::cout << dbName << ".json has been created successfully.\n";
    file << "{\n\"people\" : [\n]\n}";
}

bool PersonDatabase::appendPerson(const Person& p) {
    if (file.tellg() == 15 || !findPerson(p.phoneNumber)) {
        file.seekp(-3, std::ios_base::end);
        if (file.tellg() == EMPTYJSON) {
            file << PersonSerializer::toJson(p).str() << "\n]\n}";
        } else {
            file << "," << PersonSerializer::toJson(p).str() << "\n]\n}";
        }
        return true;
    }
    return false;
}

PersonDatabase::~PersonDatabase() {
    if (file.is_open()) file.close();
}

bool PersonDatabase::findPerson(const std::string& searchKey) {
    std::stringstream content;
    std::vector<std::string> splitArr;
    std::string temp;
    if (file) {
        content << file.rdbuf();
    }
    while (getline(content, temp, '{')) {
        splitArr.push_back(temp);
    }
    for (const auto &str: splitArr) {
        Person comp = PersonSerializer::fromJson((std::stringstream) str);
        if (searchKey == comp.phoneNumber) {
            std::cout << "Name of user: " << comp.name << std::endl;
            std::cout << "Age of user: " << comp.age << std::endl;
            std::cout << "Phone number of user: " << comp.phoneNumber << std::endl;
            std::cout << "Address of user: " << comp.address << std::endl;
            return true;
        }
    }
    return false;
}
