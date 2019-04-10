/* W zadaniu nalezy skonstruowac logiczna hierarchie klas na podstawie
 * ponizszego programu. Prosze zauwazyc, ze NumerId to osobna
 * klasa (wraper na unsigned int) sluzaca do przechowywania numeru id w 
 * wirtualnym dziekanacie.
 * 
 * Prosze nie implementowac pol w klasach bazowych jezeli nie sa one tam
 * wymagane (na podstawie ponizszego kodu).
 * 
 * Jezeli ktos chce, to uzywanie biblioteki standardowej jest dozwolone 
 * bez ograniczen. 
 * 
 * Trzeba sie zastanowic jak za pomocą funkcji pomocniczej zaimplemenetować
 * "dziedziczenie" operatora wypisywania, (prosze nie kombinowac z przyjazniami).
 */

#include <iostream>
#include "main.h"

void sprawdzWskaznik(const void* p) {
	if ( p == 0 )
		std::cout << "null ptr" << std::endl;
	else
		std::cout << "ok ptr" << std::endl;
}

void przedstawOsobe(const Osoba* poj) {
	if ( poj )
		std::cout << "Osoba: " << (*poj) << std::endl;
	else
		std::cout << "Osoba nierozpoznana." << std::endl;
}

int main() {
	NumerId idNum(1456);
	std::cout << "Przykladowe Id = " << idNum << std::endl;
	
	Dydaktyk * dd = new Dydaktyk( "Zenon Podlaski", idNum );
	sprawdzWskaznik(dynamic_cast<Pracownik*>(dd));
	przedstawOsobe(dd);

	Student * ss = new Student( "Kinga Podwawelska", NumerId(222222) );
	sprawdzWskaznik(dynamic_cast<const Pracownik*>(ss));
	przedstawOsobe(ss);

	const Wozny ww = Wozny( "Tomasz Podchorazy" );
	sprawdzWskaznik(dynamic_cast<const Pracownik*>(&ww));
	przedstawOsobe(&ww);

	std::cout << "--------" << std::endl;

	Osoba * dok =  new Doktorant( "Jozef Podbipieta", NumerId(2280), NumerId(3340) );
	const Student * s = dynamic_cast<Student*>(dok);
	const Dydaktyk * d = dynamic_cast<Dydaktyk*>(dok);  
	const Wozny * w = dynamic_cast<Wozny*>(dok);  
	sprawdzWskaznik(s);
	przedstawOsobe(s);
	sprawdzWskaznik(d);
	przedstawOsobe(d);
	sprawdzWskaznik(w);
	przedstawOsobe(w);

	std::cout << "NumId - nauczyciel = " << d->numId() << std::endl;
	std::cout << "NumId - uczen = " << s->numId() << std::endl;

	Doktorant * dokdok = dynamic_cast<Doktorant*>(dok);
	std::cout << "NumId - nauczyciel = " << dokdok->numId_nauczyciel() << std::endl;
	std::cout << "NumId - uczen = " << dokdok->numId_uczen() << std::endl;

	delete dd;
	delete ss;
	delete dok;
}

/* wynik
Przykladowe Id = <001456>
ok ptr
Osoba: Zenon Podlaski - dydaktyk
null ptr
Osoba: Kinga Podwawelska - student
ok ptr
Osoba: Tomasz Podchorazy - wozny
--------
ok ptr
Osoba: Jozef Podbipieta - doktorant
ok ptr
Osoba: Jozef Podbipieta - doktorant
null ptr
Osoba nierozpoznana.
NumId - nauczyciel = <002280>
NumId - uczen = <003340>
NumId - nauczyciel = <002280>
NumId - uczen = <003340>
*/
