#pragma once
#include <numeric>
#include <vector>
#include "Ksztalt.h"

class Trojkat : public Ksztalt {
public:
  /**
   * @brief Construct a new Trojkat object
   * 
   * @param [double] a - First side of triangle 
   * @param [double] b - Second side of triangle
   * @param [double] c - Third side of triangle
   */
  Trojkat(double a, double b, double c) {
    m_items = std::vector<double>{a, b, c};
  }
  /**
   * @brief Function which counts area of Triangle
   * 
   * @return double - Area of triangle
   */
  double polePow() const noexcept {
    const double polObwodu = this->obwod() / 2;
    double helper = 1;
    for (auto x : m_items) {
      helper *= (polObwodu - x);
    }
    return sqrt(polObwodu * helper);
  }
  /**
   * @brief Function, which prints out Triangle sides
   * 
   * @param [std::osteram&] s - Stream to print to 
   */
  void wypisz(std::ostream& s) const noexcept {
    s << "Trojkat o bokach: ";
    for(auto x : m_items) {
      s << x << " ";
    }
    s << std::endl;
  }
private:
  std::vector<double> m_items;  /** Sides of triangle **/
  /**
   * @brief Function, which counts circumference of Triangle
   * 
   * @return double - Circumference
   */
  double obwod() const noexcept {
    return std::accumulate(m_items.begin(), m_items.end(), 0.0);
  }
};
