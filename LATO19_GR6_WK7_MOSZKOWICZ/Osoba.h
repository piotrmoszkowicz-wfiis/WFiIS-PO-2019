#pragma once
#include <iostream>
#include <string>

class Osoba {
public:
    Osoba(const std::string& name) : m_name(name) {}
    friend std::ostream& operator<<(std::ostream& out, const Osoba& os) {
        return out << "Osoba: " << os.print();
    }
    virtual ~Osoba() = default;
protected:
    virtual std::string print() const {
        return m_name;
    };
    std::string m_name;
};
