#pragma once
#include <iostream>
#include <iomanip>

class NumerId {
public:
    NumerId(unsigned int num) : m_number(num) {}
    friend std::ostream& operator<<(std::ostream& out, const NumerId& numId) {
        out << "<" << std::setw(6) << std::setfill('0') << numId.getNumber() << ">";
        return out;
    }
    unsigned int getNumber() const {
        return m_number;
    }
private:
    unsigned int m_number;
};