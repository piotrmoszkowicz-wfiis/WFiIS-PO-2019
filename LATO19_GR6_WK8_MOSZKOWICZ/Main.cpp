// UWAGA!
// Nie wolno korzystać ze zmiennych i funkcji statycznych, ani ze
// zmiennych globalnych.

// Prosze zaimplementowac klase ObiektMiotajacy i klasy ExceptType od 1 do 4. 
// ObiektMiotajacy musi miec zaimplementowana metoda Rzuc(),
// natomiast klasy ExceptType1 do ExceptType4 metode PrzedstawSie(), 
// ktora wypisuje na ekranie z jakiego typu obiektem mamy do czynienia.

// Funkcja HandleExcept i instrukcje w blokach catch(ExceptType3*) i
// catch(ExceptType4*) wypisuja na ekran adres przechowywany we wskazniku
// wyjatek.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Bardzo wazne jest aby
// nie bylo zadnych wyciekow pamieci.

#include "lab08.h"
#include <iostream>

void Funkcja ()
{
	try {
		ObiektMiotajacy* miotacz = new ObiektMiotajacy;
		miotacz->Rzuc();
		std::cout << "Ukryty przekaz"<<std::endl;
	}
	catch (ExceptType1* wyjatek)
	{
		HandleExcept (wyjatek);	        // Przetworz wyjatek Except1 o adresie: ....
	}
	catch (ExceptType2* wyjatek)
	{
		HandleExcept (wyjatek);      	// Przetworz wyjatek Except2 o adresie: ....
	}
}


int main ()
{
	using namespace std;

	cout << "Wprowadzenie\n";
	ExceptType1 a; a.PrzedstawSie();	// Nazywam sie Except1
	ExceptType2 b; b.PrzedstawSie();	// Nazywam sie Except2
	ExceptType3 c; c.PrzedstawSie();	// Nazywam sie Except3
	ExceptType4 d; d.PrzedstawSie();	// Nazywam sie Except4
	cout << "Koniec wprowadzenia\n";

	try {
		Funkcja();
		cout << "Ukryty przekaz" << endl;
	}
	catch (ExceptType3* wyjatek) {
		cout << "Zlapalem wyjatek Except3 w linii " << __LINE__ << ". " 
		     << "Adres wyjatku: " << wyjatek << endl;
		delete wyjatek;
	}
	catch (ExceptType4* wyjatek) {
		cout << "Zlapalem wyjatek Except4 w linii " << __LINE__ << ". " 
		     << "Adres wyjatku: " << wyjatek << endl;
		delete wyjatek;
	}

  return 0;
}
/*
Wprowadzenie
Nazywam sie Except1
Nazywam sie Except2
Nazywam sie Except3
Nazywam sie Except4
Koniec wprowadzenia
Przetworz wyjatek Except2 o adresie: 0x562fbb8a2330
Zlapalem wyjatek Except4 w linii 59. Adres wyjatku: 0x562fbb8a2330
*/
