#ifndef ENGINEER_H
#define ENGINEER_H

#include "Person.h"

// Engineer will do protected inheritance
class Engineer : public Person {
   private:
    int _contract_cout{0};
    friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);

   protected:
    // using Person::_address;
    using Person::getAdress;
    using Person::getAge;
    using Person::getFullName;

   public:
    std::string company_name{"None"};
    // Constructor
    // using Person::Person;  // Add constructors from parent class
    Engineer();
    Engineer(const std::string& fullname, int age,
             const std::string adress, int contract_count);
    Engineer(const Engineer& source);
    ~Engineer();
    // Function
    int getContractCount();
    void setContractCount(int count);
    void BuildSomething();
    void BuildRoad();
};

#endif