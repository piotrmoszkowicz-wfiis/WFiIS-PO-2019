#pragma once

#include "InfoClass.h"

class InfoSmartPtr {
public:
    /**
     * @brief Construct a new Info Smart Ptr object
     * 
     * @param [InfoClass*]          ic_ptr          Pointer to InfoClass instance to be stored inside SmartPtr.
     */
    InfoSmartPtr(InfoClass* ic_ptr) : m_ptr(ic_ptr) {
        m_counter = new unsigned int;
        *m_counter = 1;
    }

    /**
     * @brief Construct a new Info Smart Ptr object
     * 
     * @param [const InfoSmartPtr&] isp             Reference to class to copy from.
     */
    InfoSmartPtr(const InfoSmartPtr& isp) {
        copy(isp);
    }

    /**
     * @brief Destroy the Info Smart Ptr object
     * 
     */
    ~InfoSmartPtr() {
        del();
    }

    /**
     * @brief Retruns non-const reference to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass&                          Reference to InfoClass
     */
    InfoClass& operator*() {
      return *m_ptr;  
    }

    /**
     * @brief Retruns const reference to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass&                          Reference to InfoClass
     */
    InfoClass& operator*() const {
      return *m_ptr;  
    }

    /**
     * @brief Retruns non-const pointer to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass*                          Pointer to InfoClass
     */
    InfoClass* operator->() {
        return this->getPtr();
    }

    /**
     * @brief Retruns const pointer to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass*                          Pointer to InfoClass
     */
    InfoClass* operator->() const {
        return this->getPtr();
    }

    /**
     * @brief Operator=, which copies object
     * 
     * @param [const InfoSmartPtr&]     ic         Reference to object to copy from
     * @return InfoSmartPtr&                       Copy of an object
     */
    InfoSmartPtr& operator=(const InfoSmartPtr& ic);
private:
    /**
     * @brief Function, which copies SmartPtr
     * 
     * @param [const InfoSmartPtr&]    isp         Reference to object to copy from
     */
    void copy(const InfoSmartPtr& isp);

    /**
     * @brief Cleans up SmartPtr when needed
     * 
     */
    void del();

    /**
     * @brief Retruns non-const pointer to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass*                         Pointer to InfoClass
     */
    InfoClass* getPtr() {
        return m_ptr;
    }

    /**
     * @brief Retruns const pointer to the InfoClass stored inside SmartPtr
     * 
     * @return InfoClass*                          Pointer to InfoClass
     */
    InfoClass* getPtr() const {
        return m_ptr;
    }

    /**
     * @brief Retruns non-const pointer to the number stored inside SmartPtr
     * 
     * @return unsigned int*                       Pointer to number
     */
    unsigned int* getCounterPtr() {
        return m_counter;
    }

    /**
     * @brief Retruns const pointer to the number stored inside SmartPtr
     * 
     * @return unsigned int*                       Pointer to number
     */
    unsigned int* getCounterPtr() const {
        return m_counter;
    }

    InfoClass* m_ptr;   /** Pointer to InfoClass **/
    unsigned int* m_counter;    /** Counter of use of smart pointer **/
};