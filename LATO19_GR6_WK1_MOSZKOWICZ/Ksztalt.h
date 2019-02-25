#pragma once
#include <iostream>

class Ksztalt {
  public:
    /**
     * @brief Static function, which prints out Ksztalt's data
     * 
     * @param [const Ksztalt&] k - Ksztalt, which we want to print data of 
     */
    static void wypisz(const Ksztalt& k) noexcept {
      k.wypisz(std::cout);
    }
    /**
     * @brief Static function, which prints out Ksztalt's data
     * 
     * @param [const Ksztalt*] k - Pointer to Ksztalt, which we want to print data of 
     */
    static void wypisz(const Ksztalt *k) noexcept {
      k->wypisz(std::cout);
    }
    /**
     * @brief Virtual function which counts area of Ksztalt
     * 
     * @return double - Area of Ksztalt
     */
    virtual double polePow() const noexcept = 0;
    /**
     * @brief Virtual function, which prints out data of Ksztalt
     * 
     * @param [std::osteram&] s - Stream to print to 
     */
    virtual void wypisz(std::ostream& s) const noexcept = 0;
};