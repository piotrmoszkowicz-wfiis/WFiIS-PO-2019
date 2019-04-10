#pragma once
#include <string>
#include <iostream>

/**
 * Stanislaw Teczynski
 * Piotr Moszkowicz
 */

class StringConvertable {
public:
    /**
     * @brief Virtual method, which gets raw string
     * 
     * @return [std::string]    - Raw string
     */
    virtual std::string rawString() const = 0;

    /**
     * @brief Virtual method, which gets the length
     * 
     * @return [unsigned int]   - Length of stored object
     */
    virtual unsigned int getLength() const = 0;
};