//
// Created by Marwan Negm on 17/05/2024.
//

#include "PersonSerializer.h"
#include <sstream>
    /* returns:
     * "
     * {
     *      "name" : "Marwan Negm",
     *      "age" : 19,
     *      "address" : "Arbitrary address",
     * }
     * "
     * */
std::stringstream PersonSerializer::toJson(Person p) {
    std::stringstream result;

    result<<"{\n";
    result<<"\t\"name\" : "<<"\""<<p.name<<"\""<<" ,\n";
    result<<"\t\"age\" : "<<p.age<<" ,\n";
    result<<"\t\"phoneNumber\" : "<<"\""<<p.phoneNumber<<"\""<<" ,\n";
    result<<"\t\"address\" : "<<"\""<<p.address<<"\"";
    result<<"\t\n}";

    return result;
}

Person PersonSerializer::fromJson(std::stringstream objectJson) {
    Person p;
    std::string data;
    while(objectJson>>data){
        if (data == "\"name\""){
            objectJson>>data;// Consume colon
            objectJson>>data;
            p.name = data.substr(1, data.length() - 2);
        }

        if (data == "\"age\""){
            objectJson>>data;// Consume colon
            objectJson>>data;
            p.age = atoi(data.c_str());
        }

        if (data == "\"phoneNumber\""){
            objectJson>>data;// Consume colon
            objectJson>>data;
            p.phoneNumber = data.substr(1, data.length() - 2);
        }

        if (data == "\"address\""){
            objectJson>>data;// Consume colon
            objectJson>>data;
            p.address = data.substr(1, data.length() - 2);
        }
    }
    return p;
}
