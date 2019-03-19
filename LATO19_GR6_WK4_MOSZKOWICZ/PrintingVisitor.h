#pragma once
#include <iostream>
#include "Visitor.h"

class PrintingVisitor : public Visitor {
public:
    /**
     * @brief Construct a new Printing Visitor object
     * 
     */
    PrintingVisitor() noexcept {}

    /**
     * @brief Prints out int
     * 
     * @param [IntData*]    d   Container having integer
     */
    void visit(IntData* d) noexcept;

    /**
     * @brief Prints out float
     * 
     * @param [FloatData*]  d   Container having float 
     */
    void visit(FloatData* d) noexcept;
};
