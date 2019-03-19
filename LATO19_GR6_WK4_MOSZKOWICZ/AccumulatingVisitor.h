#pragma once
#include "Visitor.h"

class AccumulatingVisitor : public Visitor {
public:
    /**
    * @brief Construct a new Accumulating Visitor object
    * 
    */
    AccumulatingVisitor() noexcept : m_sum(0.0f) {}

    /**
     * @brief Adds int to sum
     * 
     * @param [IntData*]    d   Container having integer 
     */
    void visit(IntData* d) noexcept;

    /**
     * @brief Adds float to sum
     * 
     * @param [FloatData*]  d   Conainer having float
     */
    void visit(FloatData* d) noexcept;

    /**
     * @brief Get the Total Sum object
     * 
     * @return float 
     */
    inline float getTotalSum() const noexcept {
        return m_sum;
    }
private:
    float m_sum;    /** Sum of added elements **/
};
