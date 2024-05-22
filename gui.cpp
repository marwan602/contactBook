//
// Created by Marwan Negm on 22/05/2024.
//

#include "gui.h"

void gui::vertical_line_Modes() {
    std::cout<<std::endl<<orSign<<" 1- Search"<<std::endl;
    std::cout<<orSign<<" 2- Edit"<<std::endl;
    std::cout<<orSign<<" 3- Add"<<std::endl;
    std::cout<<orSign<<" 4- Remove"<<std::endl;
}

void gui::horizontal_line() {
    for(int i=0;i<45;i++){
        std::cout<<equalsign;
    }
}

