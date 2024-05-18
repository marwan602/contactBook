//
// Created by Marwan Negm on 17/05/2024.
//

#ifndef UNTITLED6_PERSON_H
#define UNTITLED6_PERSON_H
#include <string>
#include <utility>

struct Person {
    std::string name;
    int age; // -128 to 127
    std::string phoneNumber;
    std::string address;

    Person() = default;
    Person(std::string _name, int _age, std::string _phoneNumber, std::string _address):
    name(_name), age(_age), phoneNumber(_phoneNumber), address(_address){}
};


#endif //UNTITLED6_PERSON_H
