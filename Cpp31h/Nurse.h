#ifndef NURSE_H
#define NURSE_H

#include "Person.h"

// Nurse will do protected inheritance
class Nurse : protected Person {
   private:
    int practice_certificate_id{0};

    friend std::ostream& operator<<(std::ostream& out, const Nurse& nurce);

   public:
    Nurse();
    ~Nurse();

    void TreatUnwellPerson();
};

#endif  // HURSE_H