#pragma once
#include "AttColor.h"
#include "AttFormat.h"
#include "StringConvertable.h"

class MyLine : public AttColor, public StringConvertable {
public:
    /**
     * @brief Construct a new My Line object
     * 
     * @param [char]             c   - Char of line 
     * @param [unsigned int]     len - Length of line
     * @param [AttColor::Option] opt - Color of line
     */
    MyLine(char c, unsigned int len, AttColor::Option opt) : m_char(c), m_length(len), AttColor(opt) {}

    /**
     * @brief Set the Length object
     * 
     * @param [unsigned int]     l  - New length of line 
     */
    void setLength(unsigned int l);

    /**
     * @brief Set the Char object
     * 
     * @param [char]              c  - New char to be used as line base
     */
    void setChar(char c);

    /**
     * @brief Retuns raw string
     * 
     * @return [std::string]          - Line stored in class
     */
    std::string rawString() const override;

    /**
     * @brief Get the Length object
     * 
     * @return [unsigned int]         - Length of line
     */
    unsigned int getLength() const;
private:
    char m_char; /** Base char of line **/
    unsigned int m_length; /** Length of line **/
};