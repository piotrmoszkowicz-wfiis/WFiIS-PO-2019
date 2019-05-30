#pragma once

#include <iostream>
#include <vector>

#include "TemplatedCont.h"

template<typename T>
class missing {};

class ClonesF {
public:
    /**
     * @brief Construct a new Clones F object
     * 
     */
    ClonesF() {
        m_ObjectsArray = std::vector<Cont*>();
    }

    /**
     * @brief Destroy the Clones F object
     * 
     */
    ~ClonesF() {
        for (int i = 0; i < m_ObjectsArray.size(); i++) {
            delete m_ObjectsArray[i];
        }
    }

    /**
     * @brief                                       - Adds object to our vector as example to create new objects from
     * 
     * @tparam T                                    - Type of object, which is being added 
     * @param object                                - Object, which is getting added to the vector
     */
    template<typename T>
    void add(const T& object) {
        auto newContainer = new TemplatedCont<T>(object);
        m_ObjectsArray.push_back(newContainer);
    }

    /**
     * @brief                                       - Constructs new object of type T, if example is found
     * 
     * @tparam T                                    - Type of object, which we want to construct
     * @return T&                                   - Reference to the newly constructed object / throw exception if example not found
     */
    template<typename T>
    T& clone() {
        for (int i = 0; i < m_ObjectsArray.size(); i++) {
            auto casted = dynamic_cast<TemplatedCont<T>*>(m_ObjectsArray.at(i));
            if (casted != nullptr) {
                return casted->getObject();
            }
        }
        throw missing<T>();
    }
private:
    std::vector<Cont*> m_ObjectsArray;  /** Vector of examples to create from **/
};