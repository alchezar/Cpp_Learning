#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <string_view>

class Person {
   private:
    std::string _address{"None"};
    friend std::ostream& operator<<(std::ostream& out, const Person& person);

   protected:
    std::string _first_name{"John"};
    std::string _last_name{"Doe"};
    int _age{0};

   public:
    std::string _full_name{"None"};

    // Coustructor
    Person();
    Person(std::string& first_name, std::string& last_name);
    Person(const std::string& full_name, int age, std::string address);
    ~Person();

    // Getter
    std::string getFirstName() const {
        return _first_name;
    }
    std::string getLastName() const {
        return _last_name;
    }
    std::string_view getFullName() const {
        return _full_name;
    }
    std::string getAdress() const {
        return _address;
    }
    int getAge() const {
        return _age;
    }
    // Setter declaration
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setAddress(std::string address);
    void setAge(int age);
};

#endif