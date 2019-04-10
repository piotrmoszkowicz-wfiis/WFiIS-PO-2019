#include "MyLine.h"

std::string MyLine::rawString() const {
    return std::string(m_length, m_char);
}

void MyLine::setLength(unsigned int l) {
    m_length = l;
}

void MyLine::setChar(char c) {
    m_char = c;
}

unsigned int MyLine::getLength() const {
    return m_length;
}