//
// Created by Marwan Negm on 22/05/2024.
//

#include "gui.h"
#include "PersonDatabase.h"
#include <string>
#include "Person.h"
#include <iostream>

void gui::vertical_line_Modes() {
    std::cout<<std::endl<<orSign<<" 1- Search"<<std::endl;
    std::cout<<orSign<<" 2- Add"<<std::endl;
    std::cout<<orSign<<" 3- Edit"<<std::endl;
    std::cout<<orSign<<" 4- Remove"<<std::endl;
}

void gui::horizontal_line_1() {

    for(int i=0;i<45;i++){
        std::cout<<equalsign;
    }
}
void gui::Search_gui() {
    PersonDatabase db;
    std::string searchKey;
    std::cout<<"Enter the number:"; std::cin >> searchKey;
    gui::horizontal_line_1();
    db.openDb("lol");
    std::cout<<std::endl;
    if (db.findPerson(searchKey)==false){
    std::cout<<" --> Person not found!"<<std::endl;}
    else{
        std::cout<<std::endl<<" --> The phoneNumber "<<searchKey<<" information!"<<std::endl;
    }
    gui::horizontal_line_1();
}

void gui::add_person_gui() {
    PersonDatabase db;
    db.openDb("lol");
    std::string name;
    int age;
    std::string phoneNumber;
    std::string address;
    gui::horizontal_line_1();
    std::cout << std::endl << "Enter Name:";
    std::cin >> name;
    std::cout << "Enter Age:";
    std::cin >> age;
    std::cout << "Enter PhoneNumber:";
    std::cin >> phoneNumber;
    std::cout << "Enter Address:";
    std::cin >> address;
    gui::horizontal_line_1();
    Person s(name, age, phoneNumber, address);
    std::cout<<std::endl;
    if(db.findPerson(phoneNumber)==false){
        db.appendPerson(s);
        std::cout<<" --> Person Add"<<std::endl;
    }
    else{
        std::cout<<std::endl<<" --> This number already exists!"<<std::endl;
    }
    horizontal_line_1();


}
void gui::updatePerson_gui() {
    PersonDatabase db;
    std::string person_number;
    db.openDb("lol");
    std::cout<<"Enter number:"; std::cin>>person_number;
    gui::horizontal_line_1();
    std::cout<<std::endl;
    db.updatePerson(person_number);
    gui::horizontal_line_1();
}
void gui::delete_person_gui() {
    PersonDatabase db;
    std::string person_number;
    db.openDb("lol");
    std::cout<<"Enter number:"; std::cin>>person_number;
    horizontal_line_1();
    std::cout<<std::endl;
    if(db.findPerson(person_number)==true){
        std::cout<<std::endl<<" --> contact deleted!"<<std::endl;
        horizontal_line_1();
        db.deletePerson(person_number);
        }
    else if(db.findPerson(person_number)==false){
        std::cout<<" --> contact not found!"<<std::endl;
        horizontal_line_1();
    }



}



