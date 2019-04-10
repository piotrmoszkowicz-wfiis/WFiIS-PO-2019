#pragma once
#include "Pracownik.h"

class Wozny : public Pracownik {
public:
    Wozny(const std::string& name) : Pracownik(name), Osoba(name) {}
private:
    std::string print() const override {
        return m_name + " - wozny";
    };
};
