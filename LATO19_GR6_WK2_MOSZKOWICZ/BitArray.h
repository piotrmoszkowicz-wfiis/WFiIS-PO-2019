#pragma once
#include <iostream>
#include <cstring>

#include "BitChanger.h"

class BitArray {
public:
    /**
     * @brief Construct a new Bit Array object
     * 
     * @param [unsigned int]    length              Length of BitArray 
     * @param [boolean]         shouldBeOnes        Whether should fill BitArray with ones or zeroes
     */
    BitArray(unsigned int length, bool shouldBeOnes = false) {
        m_length = length;
        m_bits = new unsigned char[(length / 8) + 1];
        for(unsigned int i = 0; i < (m_length / 8) + 1; i++) {
            if (shouldBeOnes) {
                m_bits[i] = 0xFF;
            } else {
                m_bits[i] = 0x00;
            }
        }
    }

    /**
     * @brief Destroy the Bit Array object
     * 
     */
    ~BitArray() {
        delete [] m_bits;
    }

    /**
     * @brief Prints BitArray
     * 
     */
    void print() const noexcept;

    /**
     * @brief Overload of [] operator, to access single bit from array
     * 
     * @param  [unsigned int]       pos             Position of bit to return
     * @return [bool]                               Value of single bit
     */
    inline bool operator[](unsigned int pos) const noexcept {
        unsigned int bytePos = pos / 8;
        return BitChanger(m_bits[bytePos], pos % 8);
    }

    /**
     * @brief Overload of [] operator, to access single bit from array
     * 
     * @param  [unsigned int]       pos             Position of bit to return
     * @return [BitChanger]                         Object, which can change/read single bit 
     */
    BitChanger operator[](unsigned int pos) noexcept;

    /**
     * @brief Overload of = operator to copy one BitArray to another
     * 
     * @param  [const BitArray&]    ba              BitArray which we want to copy 
     * @return [BitArray*]                          New BitArray pointer
     */
    BitArray* operator=(const BitArray& ba) noexcept {
        delete [] m_bits;
        m_bits = new unsigned char[(ba.m_length / 8) + 1];
        m_length = ba.m_length;
        std::memcpy(m_bits, ba.m_bits, (ba.m_length / 8) + 1);
        return this;
    }
private:
    unsigned char* m_bits;  /** Array of unsigned char, which contains bits **/
    unsigned int m_length;  /** Number of bits stored in BitArray **/
};
