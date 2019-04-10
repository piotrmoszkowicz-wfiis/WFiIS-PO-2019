#pragma once
#include "Osoba.h"
#include "NumerId.h"

class Student : public virtual Osoba {
public:
    Student(const std::string& name, const NumerId& number) : Osoba(name), m_numberStudent(number) {}
    NumerId numId() const {
        return m_numberStudent;
    }
protected:
    std::string print() const override {
        return m_name + " - student";
    };
    NumerId m_numberStudent;
};

