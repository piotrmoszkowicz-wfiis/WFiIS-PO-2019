#pragma once

#include "Cont.h"

template<typename T>
class TemplatedCont : public Cont {
public:
    /**
     * @brief Construct a new Templated Cont object
     * 
     * @param object                        - Object to hide inside TemplatedContainer
     */
    TemplatedCont(const T& object) : m_Object(object) {}

    /**
     * @brief Destroy the Templated Cont object
     * 
     */
    ~TemplatedCont() = default;

    /**
     * @brief Get the Object's object
     * 
     * @return T&                           - Reference to the hidden object
     */
    T& getObject() {
        return m_Object;
    }
private:
    T m_Object; /** Hidden object inside container **/
};
