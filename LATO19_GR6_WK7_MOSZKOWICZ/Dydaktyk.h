#pragma once
#include "Pracownik.h"
#include "NumerId.h"

class Dydaktyk : public Pracownik {
public:
    Dydaktyk(const std::string& name, const NumerId& number) : Pracownik(name), m_numberDydaktyk(number), Osoba(name) {}
    NumerId numId() const {
        return m_numberDydaktyk;
    }
protected:
    std::string print() const override {
        return m_name + " - dydaktyk";
    };
    NumerId m_numberDydaktyk;
};

