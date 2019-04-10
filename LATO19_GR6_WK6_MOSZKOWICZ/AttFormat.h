#pragma once

class AttFormat {
public:
    /**
     * @brief Enum of available format options
     * 
     */
    enum Option {
        BOLD = 0,
        DIM = 1,
        UNDERLINED = 2,
        RESET = 3
    };

    /**
     * @brief Construct a new Att Format object
     * 
     * @param [AttFormat::Option] opt - Format option
     */
    AttFormat(Option opt) : m_format(opt) {}

    /**
     * @brief Set the Format object
     * 
     * @param [AttFormat::Option] f  - Format option
     */
    void setFormat(AttFormat::Option f) {
        m_format = f;
    }

    /**
     * @brief Get the Format object
     * 
     * @return AttFormat::Option  - Format option
     */
    AttFormat::Option getFormat() const {
        return m_format;
    }
private:
    AttFormat::Option m_format; /** Keeps the current format **/
};
