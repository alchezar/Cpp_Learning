#include "Person.h"

#include <iostream>

//  Construntor
Person::Person() {
    std::cout << "Default constructor of Person called..." << std::endl;
}
Person::Person(std::string& first_name, std::string& last_name)
    : _first_name(first_name), _last_name(last_name) {
}
Person::Person(const std::string& full_name, int age, std::string address)
    : _full_name{full_name}, _age(age), _address(address) {
}
Person::~Person() {
}

// Setter definision
void Person::setFirstName(std::string name) {
    _first_name = name;
}
void Person::setLastName(std::string name) {
    _last_name = name;
}
void Person::setAddress(std::string address) {
    _address = address;
}

void Person::setAge(int age) {
    _age = age;
}

// Operator overloading
std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << "Person [ Full name: " << person.getFullName() << " "
        << ", Age: " << person.getAge() << " "
        << ", Adress: " << person.getAdress() << "]";
    return out;
}