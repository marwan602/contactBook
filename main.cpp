#include <iostream>
#include <fstream>
#include <sstream>
#include "PersonSerializer.h"
#include "PersonDatabase.h"
int main()
{
    Person marwan{"marwan", 19, "01288997036", "Maadi"};
    Person marwan2 = PersonSerializer::fromJson(PersonSerializer::toJson(marwan));
    std::cout<<marwan.age<<" "<<marwan.name<<marwan.phoneNumber<<std::endl;
    PersonDatabase pdb;
    pdb.openDb("lol");
    pdb.appendPerson(marwan);

}
