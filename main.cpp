#include <iostream>
#include "PersonDatabase.h"
#include "gui.h"

int main()
{
    int chooseMode;
    gui::horizontal_line_1();
    gui::vertical_line_Modes(); //prints operations on file
    gui::horizontal_line_1();
    PersonDatabase pdb;
  //  Person marwan("Marwan",18,"01288997034","Maadi");
  //  pdb.appendPerson(marwan);
        std::cout<<std::endl<<"ChooseMode:";
        std::cin >> chooseMode;
        //pdb.updatePerson("100");
       // pdb.deletePerson("01288997035");
        if(chooseMode==1){
           gui::Search_gui();
        }
        else if(chooseMode==2){
            gui::add_person_gui();
        }
        else if(chooseMode==3){
            gui::updatePerson_gui();
       }
        else if(chooseMode==4){
            gui::delete_person_gui();
        }


}

