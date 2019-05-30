#pragma once

#include <iostream>

template<typename T>
class DynArray {
public:
    /**
     * @brief Construct a new Dyn Array object
     * 
     * @param [int]         length                  Length of our not array not vector container
     */
    DynArray(int length) {
        m_data = new T[length];
        m_length = length;
    }

    /**
     * @brief Construct a new Dyn Array object
     * 
     * @param [const T&]    array                   Container to copy values from
     */
    DynArray(const DynArray& array) {
        m_data = new T[array.size()];
        m_length = array.size();

        for (int i = 0; i < m_length; i++) {
            m_data[i] = array[i];
        }
    }

    /**
     * @brief Construct a new Dyn Array object
     * 
     * @param [int]         length                  Length of normal array, which we want to construct our container from
     * @param [T*]          array                   Pointer to the normal array
     */
    DynArray(int length, const T* array) {
        m_data = new T[length];
        m_length = length;

        for (int i = 0; i < m_length; i++) {
            m_data[i] = array[i];
        }
    }

    /**
     * @brief Destroy the Dyn Array object
     * 
     */
    ~DynArray() {
        delete [] m_data;
    }

    /**
     * @brief Overload of out stream operaor, prints whole container
     * 
     * @param [std::ostream&]       s               Stream to print to 
     * @param [DynArray<T>&]        dynamicArray    Dynamic array, which we want to print
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& s, DynArray<T>& dynamicArray) {
        s << "{";
        for (int i = 0; i < dynamicArray.size() - 1; i++) {
            s << "\"" << dynamicArray[i] << "\"" << ",";
        }
        s << "\"" << dynamicArray[dynamicArray.size()- 1] << "\"}";
        
        return s;
    }

    /**
     * @brief Returns pointer to the first element of container
     * 
     * @return T* 
     */
    T* begin() const {
        return m_data;
    }

    /**
     * @brief Returns pointer to the last element of container
     * 
     * @return T* 
     */
    T* end() const {
        return m_data+m_length;
    }

    /**
     * @brief Returns number of elements, which are stored in the container
     * 
     * @return int 
     */
    int size() const {
        return m_length;
    }

    /**
     * @brief Returns certain item, which is stored in the container
     * 
     * @param [int]        index                   Index of element, we are looking for
     * @return T&                                  Value of element stored in container
     */
    T& operator[](int index) const {
        return m_data[index];
    }

    class Iterator {
        public:
            /**
             * @brief Construct a new Iterator object
             * 
             * @param [T*]  pointer               Pointer to the element, which we want to use iterator for
             */
            Iterator(T* pointer) {
                m_currentDataPointer = pointer;
            }

            /**
             * @brief Access to the next item of container by iterator
             * 
             * @return [T*]                       Pointer to the next element 
             */
            T* operator++() {
                return ++m_currentDataPointer;
            }

            /**
             * @brief Compares, whether iterator is equal with pointer
             * 
             * @param [T*]      pointer           Pointer, which we want to compare
             * @return true 
             * @return false 
             */
            bool operator!=(T* pointer) {
                return m_currentDataPointer != pointer;
            }

            /**
             * @brief Overload of opeartor *, gives access to the value behind iterator
             * 
             * @return T                          Value of iterator
             */
            T operator*() {
                return *m_currentDataPointer;
            }

            /**
             * @brief Overload of operator ->, gives access to the pointer behind iterator
             * 
             * @return T*                         Pointer to the values, stored in iterator
             */
            T* operator->() {
                return m_currentDataPointer;
            }
        private:
            T* m_currentDataPointer;    /** Pointer to the values behind iterator **/
    };
private:
    T* m_data;      /** Data stored in container **/
    int m_length;   /** Length of the container **/
};