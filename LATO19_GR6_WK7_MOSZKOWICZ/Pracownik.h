#pragma once
#include "Osoba.h"

class Pracownik : public virtual Osoba {
public:
    Pracownik(const std::string& name) : Osoba(name) {}
private:
    std::string print() const override {
        return m_name + " - pracownik";
    };
};
