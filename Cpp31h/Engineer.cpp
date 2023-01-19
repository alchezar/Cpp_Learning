#include "Engineer.h"

#include "Person.h"

// Constructor
Engineer::Engineer() {
    std::cout << "Default constructor to Engineer called..." << std::endl;
}
Engineer::Engineer(const std::string& fullname, int age,
                   const std::string adress, int contract_count)
    : Person(fullname, age, adress), _contract_cout(contract_count) {
}
Engineer::Engineer(const Engineer& source)
    : Person(source), _contract_cout(source._contract_cout) {
}
Engineer::~Engineer() {
}

// Getter
int Engineer::getContractCount() {
    return _contract_cout;
}
// Setter
void Engineer::setContractCount(int count) {
    _contract_cout = count;
}
// Function
void Engineer::BuildSomething() {
    _full_name = "Bob Dillan";
    _age = 58;
    setAddress("Building area");
}

void Engineer::BuildRoad() {
    company_name = "Comfortbud";
}

// Friend
std::ostream& operator<<(std::ostream& out, const Engineer& engineer) {
    out << "Engineer [ Full name: " << engineer.getFullName() << " "
        << ", Age: " << engineer.getAge() << " "
        << ", Adress: " << engineer.getAdress() << " "
        << ", Contract count: " << engineer._contract_cout << "]";
    return out;
}
