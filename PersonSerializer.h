//
// Created by Marwan Negm on 17/05/2024.
//

#ifndef UNTITLED6_PERSONSERIALIZER_H
#define UNTITLED6_PERSONSERIALIZER_H

#include "Person.h"
class PersonSerializer {
public:
    static std::stringstream toJson(Person p);
    static Person fromJson(std::stringstream objectJson);
};


#endif //UNTITLED6_PERSONSERIALIZER_H
