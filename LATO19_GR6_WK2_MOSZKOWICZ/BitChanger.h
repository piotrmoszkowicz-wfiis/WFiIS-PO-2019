#pragma once
#include <iostream>

class BitChanger {
public:
    /**
    * @brief Construct a new Bit Changer object
    * 
    * @param [unsigned char&]       bytePtr         Reference to single byte, which single bit is stored 
    * @param [unsigned int]         bitNumber       Number of bit, which we want to access
    */
    BitChanger(unsigned char& bytePtr, unsigned int bitNumber) noexcept : m_bytePtr(bytePtr), m_bitNumber(bitNumber) {}

    /**
     * @brief Overload of = operator, which changes value of single bit
     * 
     * @param  [boolean]            valueToSet      What value bit should be set to
     * @return [BitChanger&]                        Reference to BitChanger with changed bit
     */
    inline BitChanger& operator=(bool valueToSet) noexcept {
        if (valueToSet) {
            m_bytePtr |= 1 << m_bitNumber;
        } else {
            m_bytePtr &= ~(1 << m_bitNumber);
        }
    }

    /**
     * @brief Overload of bool operator, which retrives value of single bit
     * 
     * @return                                      Value of bit
     */
    inline operator bool() const noexcept {
        return static_cast<bool>( m_bytePtr & (1 << m_bitNumber) );
    }
private:
    unsigned char& m_bytePtr;   /** Reference to byte, where bit is stored **/
    unsigned int m_bitNumber;   /** Number of bit in byte **/
};
