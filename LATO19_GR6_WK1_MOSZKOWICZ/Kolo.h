#pragma once
#include <cmath>

#include "Ksztalt.h"

class Kolo : public Ksztalt {
  public:
    /**
     * @brief Construct a new Kolo object
     * 
     * @param r 
     */
    Kolo(double r) {
      m_radius = r;
    }
    /**
     * @brief Function which counts area of Kolo
     * 
     * @return double - Area of round
     */
    double polePow() const noexcept {
      return 3.1415 * pow(m_radius, 2);
    }
    /**
     * @brief Function, which prints out radius
     * 
     * @param [std::osteram&] s - Stream to print to 
     */
    void wypisz(std::ostream& s) const noexcept {
      s << "Kolo o promieniu: " << m_radius << std::endl;
    }
  private:
    double m_radius;  /** Radius **/
};
