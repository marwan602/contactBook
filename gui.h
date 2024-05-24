//
// Created by Marwan Negm on 22/05/2024.
//

#ifndef UNTITLED6_GUI_H
#define UNTITLED6_GUI_H
#include <iostream>
#include "PersonDatabase.h"
#include "Person.h"

class gui{
public:
    static void horizontal_line_1();
    static void vertical_line_Modes();
    static void Search_gui();
    static void updatePerson_gui();
    static void add_person_gui();
    static void delete_person_gui();
private:
    static const char orSign='|';
    static const char equalsign='=';
};


#endif //UNTITLED6_GUI_H
