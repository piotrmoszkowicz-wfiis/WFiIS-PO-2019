/* Dziedziczenie wielokrotne: Printer
*
* Do napisania sa trzy glowne klasy: MyText (przechowujaca tekst i opcje 
* formatowania i kolorowania), MyLine (przechowujaca styl, dlugosc i kolor
* linii), MyPrinter - wypisze ladnie sformatowany kod, wycentrowany.
* 
* Nalezy dopisac kilka klas bazowych, dzieki ktorym bedzie mozna uzyc 
* mechanizmu polimorfizmu do obslugi danych. Klasa MyPrinter jest prawie gotowa,
* nalezy dopisac jedynie wnetrze funkcji print. Pozostalej czesci pliku 
* nie mozna zmieniac.
*
* Zadania do zrobienia w domu:
* ** mozliwosc ustawienia dwoch opcji formatowania, 
*    np. AttFormat::BOLD | AttFormat::UNDERLINED;
* ** zaimplementowac numerowanie linii. 
* 
* Polecane uzywanie std::string. Ilosc znakow mozna sprawdzic metoda size()
*/

#include "MyText.h"
#include "MyLine.h"
#include "ConsolePrinter.h"
#include <iostream>

int main()
{
	const AttFormat * ptrFor;
	const AttColor * ptrCol;
	
	////////////////////////////////////////////////////////////////////
	MyLine line('*', 60, AttColor::MAGENTA);	
	
	ptrCol = &line;
	// ptrFor = &line; -> blad kompilacji!!!
	
	std::cout << ConsolePrinter::controlSeq( ptrCol->getColor() );
	std::cout << line.rawString();
	std::cout << ConsolePrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	MyText text("JULIUSZ SLOWACKI", AttFormat::BOLD, AttColor::GREEN);
	
	ptrCol = &text;
	ptrFor = &text;
	
	std::cout << ConsolePrinter::controlSeq( ptrFor->getFormat() ) 
	          << ConsolePrinter::controlSeq( ptrCol->getColor() );
	std::cout << std::string(22, ' ') << text.rawString() << std::endl;
	std::cout << line.rawString() << ConsolePrinter::resetSeq() << std::endl;
	          
	////////////////////////////////////////////////////////////////////
	ConsolePrinter printer(60);

	line.setLength(50);
	line.setChar('-');
	line.setColor( AttColor::GRAY );
	printer.print( line );
	
	text.setFormat( AttFormat::RESET );
	text.setColor( AttColor::WHITE );
	text.setText("Lecz zaklinam: niech zywi nie traca nadziei");
	printer.print( text );
	text.setText("I przed narodem niosa oswiaty kaganiec;");
	printer.print( text );
	
	printer.print( line );
	
	text.setColor( AttColor::RED );
	text.setText("A kiedy trzeba, na smierć ida po kolei,");
	printer.print( text );
	text.setText("Jak kamienie, przez Boga rzucane na szaniec!");
	printer.print( text );
				
	printer.print( line );
		
	return 0;
}

/* Output (oczywiscie pokolorowany)
************************************************************
                      JULIUSZ SLOWACKI
************************************************************
     --------------------------------------------------     
        Lecz zaklinam: niech zywi nie traca nadziei         
          I przed narodem niosa oswiaty kaganiec;           
     --------------------------------------------------     
          A kiedy trzeba, na smierć ida po kolei,           
        Jak kamienie, przez Boga rzucane na szaniec!        
     --------------------------------------------------     

*/
