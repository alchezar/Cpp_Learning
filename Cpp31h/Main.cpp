#include <iostream>

#include "CivilEng.h"
#include "Engineer.h"
#include "Nurse.h"
#include "Person.h"
#include "Player.h"

int main() {
    // Creating class members
    Engineer engineer_1;
    std::cout << "-----------------" << '\n';
    CivilEng civil_1("Bob Snail", 18, "vul. Stepana Bandery", 9, 2);
    civil_1.setContractCount(5);

    civil_1.BuildRoad();
    civil_1.Engineer::BuildRoad();
    civil_1.Engineer::Person::getAge();
    civil_1.Person::getAdress();

    std::cout << civil_1 << '\n';
    std::cout << "-----------------" << '\n';
    Player player_1;
    std::cout << "-----------------" << '\n';
    Engineer engineer_2("Ivan Kinder", 29, "Heroes of UPA", 3);
    std::cout << "Engineer 2: " << engineer_2 << '\n';
    std::cout << "-----------------" << '\n';
    Engineer engineer_3(engineer_2);
    std::cout << "Engineer 3: " << engineer_3 << '\n';
}