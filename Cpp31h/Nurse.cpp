#include "Nurse.h"

#include "Person.h"
#include "Player.h"

// Counstructor
Nurse::Nurse() {
}
Nurse::~Nurse() {
}

// Function
void Nurse::TreatUnwellPerson() {
    _full_name = "Betty Red";
    _age = 33;
    setAddress("Hospital");
}

// Friend
std::ostream& operator<<(std::ostream& out, const Nurse& nurse) {
    out << "Nurse [ Full name: " << nurse.getFullName() << " "
        << ", Age: " << nurse.getAge() << " "
        << ", Adress: " << nurse.getAdress() << "]";
    return out;
}
