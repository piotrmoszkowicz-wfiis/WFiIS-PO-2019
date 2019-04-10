#include "ConsolePrinter.h"
#include "MyText.h"
#include "MyLine.h"
#include <iostream>

ConsolePrinter::ConsolePrinter(unsigned int width)
	: m_width(width) 
{

}

////////////////////////////////////////////////////////////////////////
//  Jedyna metoda klasy MyPrinter ktora powinni Panstwo modyfikowac.  //
////////////////////////////////////////////////////////////////////////
void ConsolePrinter::print( const StringConvertable & obj ) const
{
	unsigned int spaces = (m_width - obj.getLength()) / 2;
	const std::string sp = std::string(spaces, ' ');
	auto ptr = const_cast<StringConvertable*>(&obj);
	auto format = dynamic_cast<AttFormat*>(ptr);
	auto color = dynamic_cast<AttColor*>(ptr);

	if (format != nullptr) {
		std::cout << controlSeq(format->getFormat());
	}

	if (color != nullptr) {
		std::cout << controlSeq(color->getColor());
	}

	std::cout << sp << obj.rawString() << sp << std::endl;
}

////////////////////////////////////////////////////////////////////////
///                                                                  ///
///          ANSI/VT100 TERMINAL OUTPUT CONTROL SEQUENCES            ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

const char * ConsolePrinter::resetSeq()
{
	return "\e[0m";
}

// formats: BOLD, DIM, UNDERLINED, RESET
const char * ConsolePrinter::controlSeq( AttFormat::Option opt )
{
	switch(opt)
	{
		case AttFormat::BOLD :
			return "\e[1m";
		case AttFormat::DIM :
			return "\e[2m";
		case AttFormat::UNDERLINED :
			return "\e[4m";
		default:
			return resetSeq();
	}
}

// colors: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, RESET
const char * ConsolePrinter::controlSeq( AttColor::Option opt )
{
	switch(opt)
	{
		case AttColor::BLACK :
			return "\e[30m";
		case AttColor::RED :
			return "\e[31m";
		case AttColor::GREEN :
			return "\e[32m";
		case AttColor::YELLOW :
			return "\e[33m";
		case AttColor::BLUE :
			return "\e[34m";
		case AttColor::MAGENTA :
			return "\e[35m";
		case AttColor::CYAN :
			return "\e[36m";
		case AttColor::GRAY :
			return "\e[90m";
		case AttColor::WHITE  :
			return "\e[97m";
		default:
			return resetSeq();
	}
}

