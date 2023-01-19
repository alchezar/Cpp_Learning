#include "CivilEng.h"

// Constructor
CivilEng::CivilEng() {
    std::cout << "Default constructor of Civil called..." << std::endl;
}
CivilEng::CivilEng(const std::string& fullname, int age,
                   const std::string adress, int contract_count, int years)
    : Engineer(fullname, age, adress, contract_count),
      years_of_practice(years) {
}
CivilEng::CivilEng(const CivilEng& course)
    : Engineer(course), years_of_practice(course.years_of_practice) {
}
CivilEng::~CivilEng() {
}
// Function
void CivilEng::BuildRoad() {
    // getFullName();
    // _full_name = "YU";
    company_name = "Ginko";
}
// Friend
std::ostream& operator<<(std::ostream& out, CivilEng civil) {
    out << "Engineer [ Full name: " << civil.getFullName() << " "
        << ", Age: " << civil.getAge() << " "
        << ", Adress: " << civil.getAdress() << " "
        << ", Contract count: " << civil.getContractCount()
        << ", Years of practice: " << civil.years_of_practice << "]";
    return out;
}
