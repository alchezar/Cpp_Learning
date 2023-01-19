#ifndef CIVILENG_H
#define CIVILENG_H

#include "Engineer.h"
#include "Person.h"

// Civil Engineer will do public inheritance to protected class
class CivilEng : public Engineer {
   private:
    friend std::ostream& operator<<(std::ostream& out, CivilEng civil);

   public:
    int years_of_practice{0};
    CivilEng();
    CivilEng(const std::string& fullname, int age, const std::string adress,
             int contract_count, int years_of_practice);
    CivilEng(const CivilEng& course);
    ~CivilEng();
    // using Engineer::Engineer;

    void BuildRoad();
};

#endif