//
// Created by Marwan Negm on 17/05/2024.
//

#include "PersonDatabase.h"
#include "PersonSerializer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

const int EMPTYJSON = 18;

bool fileExists(const std::string& dbName) {
    std::ifstream ifile;
    ifile.open(dbName + ".json");
    return (bool) ifile;
}

void PersonDatabase::openDb(const std::string& dbName) {
    if (fileExists(dbName)) {
        file.open(dbName + ".json");
        file.seekp(0,std::ios_base::end);
        std::cout<<file.tellg();
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
    file.seekp(0,std::ios_base::end);
    if (file.tellg() == EMPTYJSON || !findPerson(p.phoneNumber)) {
        file.seekp(-3, std::ios_base::end);
        if (file.tellg() == EMPTYJSON-3) {
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
std::vector<Person> PersonDatabase::getAllPeople(){
    std::stringstream content;
    std::vector<Person> splitArr;
    std::string temp;
    if (file) {
        content << file.rdbuf();
    }
    while (getline(content, temp, '{')) {
        splitArr.push_back(PersonSerializer::fromJson((std::stringstream) temp));
    }
    return splitArr;
}
bool PersonDatabase::findPerson(const std::string& searchKey) {
    for (const auto& obj: getAllPeople()) {
        if (searchKey == obj.phoneNumber) {
            std::cout << "Name of user: " << obj.name << std::endl;
            std::cout << "Age of user: " << obj.age << std::endl;
            std::cout << "Phone number of user: " << obj.phoneNumber << std::endl;
            std::cout << "Address of user: " << obj.address << std::endl;
            return true;
        }
    }
    return false;
}

bool PersonDatabase::deletePerson(const std::string &searchKey) {
    /*
     * Use get all people to get a _Vector_ (not array) of people
     * Recreate database while skipping over the unwanted person
     */
    return false;
}

bool PersonDatabase::updatePerson(const std::string &searchKey) {
    /*
     * Get all people to get vector of people
     * iterate over people till you find the phone number matching the search key
     * edit what is requested
     * recreate database.
     */
    return false;
}
