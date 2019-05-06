#pragma once
#include <iostream>
#include <string>

class ObiektMiotajacy {
public:
    ObiektMiotajacy() {}
    void Rzuc() const;
};

class ExceptTypeBoilerPlate {
public:
    ExceptTypeBoilerPlate(const std::string& name, const ObiektMiotajacy* obiektMiotajacy) : m_name(name), m_obiektMiotajacy(obiektMiotajacy) {}
    ~ExceptTypeBoilerPlate() {
        delete m_obiektMiotajacy;
    }
    void PrzedstawSie() const {
        std::cout << "Nazywam sie " << m_name << std::endl;
    }
    std::string getName() const {
        return m_name;
    }
protected:
    std::string m_name;
    const ObiektMiotajacy* m_obiektMiotajacy;
};

class ExceptType1 : public ExceptTypeBoilerPlate {
public:
    ExceptType1(const ObiektMiotajacy* obiektMiotajacy = nullptr, std::string name = "Except1") : ExceptTypeBoilerPlate(name, obiektMiotajacy) {}
};

class ExceptType2 : public ExceptTypeBoilerPlate {
public:
    ExceptType2(const ObiektMiotajacy* obiektMiotajacy = nullptr, std::string name = "Except2") : ExceptTypeBoilerPlate(name, obiektMiotajacy) {}
};

class ExceptType3 : public ExceptType1 {
public:
    ExceptType3(const ObiektMiotajacy* obiektMiotajacy = nullptr) : ExceptType1(obiektMiotajacy, "Except3") {}
};

class ExceptType4 : public ExceptType2 {
public:
    ExceptType4(const ObiektMiotajacy* obiektMiotajacy = nullptr) : ExceptType2(obiektMiotajacy, "Except4") {}
};

inline void HandleExcept(ExceptType1* exception) {
    std::cout << "Przetworz wyjatek Except1 o adresie: " << exception << std::endl;
    throw;
}

inline void HandleExcept(ExceptType2* exception) {
    std::cout << "Przetworz wyjatek Except2 o adresie: " << exception << std::endl;
    throw;
}