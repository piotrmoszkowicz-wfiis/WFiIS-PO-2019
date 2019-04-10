#include "MyText.h"

std::string MyText::rawString() const {
    return m_str;
}

void MyText::setText(std::string s) {
    m_str = s;
}

unsigned int MyText::getLength() const {
    return m_str.length();
}