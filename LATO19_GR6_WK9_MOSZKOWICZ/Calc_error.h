#pragma once

#include <stdexcept>
#include <vector>

#include "Licznik_Poziomow.h"

class Calc_error : public std::runtime_error {
public:
    /**
     * @brief Construct a new Calc_error object
     * 
     * @param [std::runtime_error*]         nErr            Next error in the hierarchy 
     * @param [std::string]                 text            Text of current error 
     * @param [std::string]                 file            File, where the error occured 
     * @param [int]                         line            Line of code, where the error occured 
     */
    Calc_error(std::runtime_error* nErr, std::string text, std::string file, int line)
        : std::runtime_error(text + ", [plik = " + file + ", linia = " + std::to_string(line) + "]"), nextError(nErr) {}
    
    /**
     * @brief Destroy the Calc_error object
     * 
     */
    ~Calc_error() = default;

    /**
     * @brief Handles throwing all the exceptions
     * 
     */
    static void handler();

    friend class LicznikPoziomow;
private:
    std::runtime_error* nextError;  /** Pointer to the next error in the hierarchy **/
};
