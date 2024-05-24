//
// Created by Marwan Negm on 17/05/2024.
//

#include "PersonDatabase.h"
#include "PersonSerializer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
bool fileExists(const std::string& dbName) {
    std::ifstream ifile;
    ifile.open(dbName + ".json");
    return (bool) ifile;
}

void PersonDatabase::openDb(const std::string& dbName) {
    if (fileExists(dbName)) {
        file.open(dbName + ".json");
        this->dbName=dbName;
        file.seekp(0,std::ios_base::end);
        return;
    }
    createDb(dbName);
}

void PersonDatabase::createDb(const std::string& dbName) {
    this->dbName=dbName;
    file.open(this->dbName+".json", std::ios::out);
    file << "{\n\"people\" : [\n]\n}";

}

bool PersonDatabase::appendPerson(const Person& p) {
    file.seekg(0);
    std::ifstream reader;
    reader.open(dbName+".json",std::ios::in);
    std::stringstream contentHolder;
    contentHolder << reader.rdbuf();
    reader.close();
    std::string content = contentHolder.str();
    std::string newContent;
    std::ifstream read;
    bool flag = findPerson(p.phoneNumber);
    if (!flag) {
        size_t endPos = content.rfind("\n]\n}");
        if (content.find('}') == content.rfind('}')) {
            newContent = content.substr(0, endPos) + PersonSerializer::toJson(p).str() + "\n]\n}";
        } else {
            newContent = content.substr(0, endPos) + ",\n" + PersonSerializer::toJson(p).str() + "\n]\n}";
        }
        file.close();
        file.open(dbName + ".json", std::ios::in|std::ios::out | std::ios::trunc);
        file<<newContent;

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
    Person p;
    if (file) {
        file.seekp(0);
        content << file.rdbuf();
    }
    while (getline(content, temp, '}')) {
        p = PersonSerializer::fromJson((std::stringstream) temp);
        splitArr.push_back(p);
    }
    if (!splitArr.empty())
        splitArr.pop_back();
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

void PersonDatabase::deletePerson(const std::string &searchKey) {
    std::vector<Person> people = getAllPeople();
    std::ofstream temp;
    temp.open(dbName + ".json", std::ios::out | std::ios::trunc);

    temp << "{\n\"people\" : [\n";

    bool first = true;
    for (const auto& person : people) {
        if (person.phoneNumber != searchKey) {
            if (!first) {
                temp << ",\n";
            }
            temp << PersonSerializer::toJson(person).str();
            first = false;
        }
    }

    temp << "\n]\n}";
    temp.close();
}


bool PersonDatabase::updatePerson(const std::string &searchKey) {
    /*
     * Get all people to get vector of people
     * iterate over people till you find the phone number matching the search key
     * edit what is requested
     * recreate database.
     */
    std::vector<Person> people = getAllPeople();
    bool found = false;
    bool dupeCheck=false;
    int counter=0;
    std::string newPN;
    for (auto& person : people) {
        if (person.phoneNumber == searchKey) {
            std::cin.ignore();
            std::cout << "Enter new name:";
            std::getline(std::cin, person.name);
            std::cout << "Enter new age:";
            std::cin >> person.age;
            std::cin.ignore();
            std::cout << "Enter new phone number:";
            std::getline(std::cin, person.phoneNumber);
            std::cout << "Enter new address:";
            std::getline(std::cin, person.address);
            newPN=person.phoneNumber;
            found = true;
            break;
        }
    }
    for (const auto& check: people) if(check.phoneNumber==newPN) counter++;
    if (counter>1) dupeCheck=true;
    if (found&& !dupeCheck) {

        std::ofstream outFile(dbName+".json", std::ios::out | std::ios::trunc);


        outFile << "{\n\"people\" : [\n";
        for (size_t i = 0; i < people.size(); ++i) {
            outFile << PersonSerializer::toJson(people[i]).str();
            if (i < people.size() - 1) {
                outFile << ",\n";
            }
        }
        outFile << "\n]\n}";
        std::cout<<std::endl<<" --> The contact has been successfully updated!"<<std::endl;
        outFile.close();
        return true;
    } else {
        if (!dupeCheck)
            std::cout << "Person with phone number " << searchKey << " not found.\n";
        else
            std::cout <<std::endl<< " --> Person with phone number " << newPN << " already exists!"<<std::endl;
        return false;
    }
}