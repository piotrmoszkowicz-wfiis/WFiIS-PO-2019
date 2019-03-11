#include "InfoClass.h"

const std::string InfoClass::info() const {
    return "info = " + m_str;
}

void InfoClass::info(const std::string& s) {
    m_str = s;
}

const std::string InfoSuperClass::info() const {
    return "info = " + m_str + ", num = " + std::to_string(m_number);
}