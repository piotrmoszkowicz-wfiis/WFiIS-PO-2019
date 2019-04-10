#pragma once
#include "Dydaktyk.h"
#include "Student.h"

class Doktorant : public Dydaktyk, public Student {
public:
    Doktorant(const std::string& name, const NumerId& numberDyd, const NumerId& numberStud) : Dydaktyk(name, numberDyd), Student(name, numberStud), Osoba(name) {}
    NumerId numId_nauczyciel() const {
        return m_numberDydaktyk;
    }
    NumerId numId_uczen() const {
        return m_numberStudent;
    }
private:
    std::string print() const override {
        return m_name + " - doktorant";
    }
};
