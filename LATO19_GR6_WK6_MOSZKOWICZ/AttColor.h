#pragma once

class AttColor {
public:
    /**
     * @brief Enum of available color options
     * 
     */
    enum Option {
        BLACK = 0,
        RED = 1,
        GREEN = 2,
        YELLOW = 3,
        BLUE = 4,
        MAGENTA = 5,
        CYAN = 6,
        GRAY = 7,
        WHITE = 8
    };

    /**
     * @brief Construct a new Att Color object
     * 
     * @param [AttColor::Option] opt - Color option
     */
    AttColor(Option opt) : m_color(opt) {}

    /**
     * @brief Set the Color object
     * 
     * @param [AttColor::Option] c   - New color 
     */
    void setColor(AttColor::Option c) {
        m_color = c;
    }

    /**
     * @brief Get the Color object
     * 
     * @return [AttColor::Option]    - Current color 
     */
    AttColor::Option getColor() const {
        return m_color;
    }
protected: 
    AttColor::Option m_color; /** Color **/
};