#pragma once

class IntData;
class FloatData;

class Visitor {
public:
    /**
     * @brief Construct a new Visitor object
     * 
     */
    Visitor() noexcept = default;

    /**
     * @brief Destroy the Visitor object
     * 
     */
    virtual ~Visitor() noexcept = default;

    /**
     * @brief Abstract method, which visits int container
     * 
     * @param [IntData*]    d   Container having integer
     */
    virtual void visit(IntData* d) noexcept = 0;

    /**
     * @brief Abstract method, which visits float container
     * 
     * @param [FloatData*]  d   Container having float 
     */
    virtual void visit(FloatData* d) noexcept = 0;
};
