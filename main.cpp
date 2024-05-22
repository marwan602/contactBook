#include <iostream>
#include <fstream>
#include <sstream>
#include "PersonSerializer.h"
#include "PersonDatabase.h"
#include "gui.h"
int main()
{
    gui::horizontal_line();
    gui::vertical_line_Modes(); //prints operations on file
    gui::horizontal_line();
    PersonDatabase pdb;
    Person marwan("Marwan",18,"01288997036","Maadi");
    pdb.openDb("lol");
    pdb.appendPerson(marwan);

}
