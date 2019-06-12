#pragma once

#include <cstring>
#include <vector>

/**
 * @brief Structure which defines whether class contains POD data or not
 * 
 * @tparam T                -   Type of class
 */
template<typename T>
struct is_pod {
    const static bool pod = false;
};

/**
 * @brief Class which defines swap method for bubble sort
 * 
 * @tparam T                -   Type of item to swap
 * @tparam isPod            -   Whether we can use POD method to swap or not
 */
template <typename T, bool isPod>
class Swap {
public:
    /**
     * @brief Swap method, which changes places of two items by copying memory
     * 
     * @param a             -   Item A 
     * @param b             -   Item B 
     */
    static void swap(T& a, T& b) {
        T copy; 
        std::memcpy(&copy, &a, sizeof(a));
        std::memcpy(&a, &b, sizeof(b));
        std::memcpy(&b, &copy, sizeof(copy));
    }
private:
    /**
     * @brief Private constructor - we want to use only static method swap
     * 
     */
    Swap();
};

/**
 * @brief Class which defines swap method when POD = false
 * 
 * @tparam T 
 */
template <typename T>
class Swap<T, false> {
public:
    /**
     * @brief Swap method, which changes places of two items by having a copy
     * 
     * @param a             -   Item A 
     * @param b             -   Item B 
     */
    static void swap(T& a, T& b) {
        T copy = a;
        a = b;
        b = copy;
    }
private:
    /**
     * @brief Private constructor - we want to use only static method swap
     * 
     */
    Swap();
};

/**
 * @brief Class which is container of data
 * 
 * @tparam T                -   Data which will be stored inside container 
 */
template <typename T>
class Vect {
public:
    /**
     * @brief Construct a new Vect object
     * 
     * @param size          -   Size of container
     */
    Vect(int size) {
        m_data = std::vector<T>(size);
    };

    /**
     * @brief Sorts container's content via Bubble Sort method
     * 
     * @param [(const T& a, const T& b) => bool)]   porownanie    -   Comparator function for sorting
     */
    void buble_sort(bool (*porownanie)(const T& a, const T& b)) {
        for (int i = 0; i < m_data.size(); i++) {
            for (int j = i + 1; j < m_data.size(); j++) {
                if (porownanie(m_data[i], m_data[j])) {
                    Swap<T, is_pod<T>::pod>::swap(m_data[i], m_data[j]);
                }
            }
        }
    };

    /**
     * @brief Returns size of container
     * 
     * @return [const int]                  -   Size of conainer 
     */
    const int size() const {
        return m_data.size();
    };

    /**
     * @brief Returns size of container
     * 
     * @return [const int]                  -   Size of conainer 
     */
    int size() {
        return m_data.size();
    };

    /**
     * @brief Overload of [] operator, returns single item of container via index
     * 
     * @param [int]     index               -   Index of item to retrive
     * @return [const T&]                   -   Reference to the item
     */
    const T& operator[](int index) const {
        return m_data[index];
    };

    /**
     * @brief Overload of [] operator, returns single item of container via index
     * 
     * @param [int]     index               -   Index of item to retrive 
     * @return [T&]                         -   Reference to the item
     */
    T& operator[](int index) {
        return m_data[index];
    };
private:
    std::vector<T> m_data;  /** Vector of our data **/
};