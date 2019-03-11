#pragma once
#include <iostream>
#include <string>

class InfoClass {
public:
    /**
    * @brief Construct a new Info Class object
    * 
    * @param [const char*] t    Text stored in InfoClass
    */
    InfoClass(const char* t) : m_str(std::string(t)) {
        std::cout << "++ Tworze obiekt InfoClass: info = " << m_str << std::endl;
    }

    /**
     * @brief Destroy the Info Class object
     * 
     */
    virtual ~InfoClass() {
        std::cout << "++ Usuwam obiekt InfoClass: info = " << m_str << std::endl;
    }

    /**
     * @brief Gets information about InfoClass
     * 
     * @return std::string      Formatted text with m_str
     */
    virtual const std::string info() const;

    /**
     * @brief Sets information about InfoClass
     * 
     * @param const std::string& s     New text to be stored in class 
     */
    void info(const std::string& s);
protected:
    std::string m_str;  /** Text stored in class **/
};

class InfoSuperClass : public InfoClass {
public:
    /**
     * @brief Construct a new Info Super Class object
     * 
     * @param [const char*] t  Text to be stored in class 
     * @param [int]         n  Number to be stored in class 
     */
    InfoSuperClass(const char* t, int n) : InfoClass(t), m_number(n) {}

    /**
     * @brief Get information about InfoSuperClass
     * 
     * @return std::string     Formatted text with m_str 
     */
    const std::string info() const;
private:
    int m_number;   /** Number stored in class **/
};
