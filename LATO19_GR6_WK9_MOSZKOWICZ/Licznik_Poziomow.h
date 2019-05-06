#pragma once

#include <iostream>
#include <string>

class LicznikPoziomow {
public:
    /**
     * @brief Construct a new Licznik Poziomow object
     * 
     */
    LicznikPoziomow() {
        LicznikPoziomow::level++;
        std::cout << "Rozpoczynamy poziom numer " << LicznikPoziomow::level << "." << std::endl;
    };

    /**
     * @brief Destroy the Licznik Poziomow object
     * 
     */
    ~LicznikPoziomow() {
        std::cout << "Konczymy poziom numer " << LicznikPoziomow::level << "." << std::endl;
        LicznikPoziomow::level--;
    };

    static int level; /** Current level of the error depth **/
};