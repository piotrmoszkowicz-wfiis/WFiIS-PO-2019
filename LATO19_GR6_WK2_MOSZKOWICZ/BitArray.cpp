#include "BitArray.h"

void BitArray::print() const noexcept {
    unsigned int curByte = m_length;
    for(unsigned int i = 0; i < m_length; i++) {
        bool v = (*this)[m_length - i - 1];
        curByte--;
        std::cout << v;
        if (curByte%8 == 0) {
            std::cout << " <-" << curByte << " ";
        }    
    }
}

BitChanger BitArray::operator[](unsigned int pos) noexcept {
    unsigned int bytePos = pos / 8;
    return BitChanger(m_bits[bytePos], pos % 8);
}