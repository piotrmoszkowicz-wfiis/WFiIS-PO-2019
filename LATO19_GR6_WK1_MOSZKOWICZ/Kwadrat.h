#pragma once
#include "Ksztalt.h"

class Kwadrat : public Ksztalt {
  public:
    /**
     * @brief Construct a new Kwadrat object
     * 
     * @param [double] a - Side of box 
     */
    Kwadrat(double a) : m_a(a){}
    /**
     * @brief Function which counts area of Kwadrat
     * 
     * @return double - Area of box
     */
    double polePow() const noexcept {
      return m_a * m_a;
    }
    /**
     * @brief Function, which prints out box sides
     * 
     * @param [std::osteram&] s - Stream to print to 
     */
    void wypisz(std::ostream& s) const noexcept {
      s << "Kwadrat o boku: " << m_a << std::endl;
    }
  private:
    double m_a; /** box side **/
};
