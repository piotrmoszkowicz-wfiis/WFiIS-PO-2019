#pragma once
#include "AttColor.h"
#include "AttFormat.h"
#include "StringConvertable.h"

class MyText : public AttColor, public AttFormat, public StringConvertable {
public:
    /**
     * @brief Construct a new My Text object
     * 
     * @param [const str::string] str   - String to be stored in class 
     * @param [AttFormat::Option] f     - Format option
     * @param [AttColor::Option]  c     - Color option 
     */
    MyText(const std::string str, AttFormat::Option f, AttColor::Option c) : m_str(str), AttFormat(f), AttColor(c) {}

    /**
     * @brief Set the Text object
     * 
     * @param [std::string] s           - New text to be stored
     */
    void setText(std::string s);

    /**
     * @brief Retuns raw string
     * 
     * @return [std::string]            - String stored in class
     */
    std::string rawString() const override;

    /**
     * @brief Get the Length object
     * 
     * @return [unsigned int]           - Length of MyText
     */
    unsigned int getLength() const;
private:
    std::string m_str; /** Text stored in class **/
};