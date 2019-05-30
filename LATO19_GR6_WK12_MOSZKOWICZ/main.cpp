/* celem zadania jest napisanie klasy fabryki pozwalajacej 
   na konstrukcje/klonowanie obiektow dowolnego typu. 
   Najpierw do fabryki wstrzykujemy metoda add() oryginal. 
   Metoda clone() robi kopie z oryginalu,
   ale jesli "orginal" danego typu nie istnieje generowany jest wyjatek.

   Kompilwowac do pliku cfac z opcjami -Wall -g

   UWAGA: Kluczem w tym zadaniu jest przypomnienie sobie jaki zrobic 
   kontener polimorficzny.
   UWAGA: Poza widocznymi klasami trzeba bedzie wymyslic dodatkowa hierarchie, 
   ktora pozwoli na przechowanie oryginalow obiektow dowolnych klas.

 */


#include <iostream>
#include <string>

#include "ClonesF.h"


struct A{
  A(const std::string& m) : msg( m ) {}
  std::string msg;
};
struct B{
  int x;
};
struct C{
  double v;
};

int main() {
  // tu mamy dwa obiekty, ktore sa w stanie produkowac nowe obiekty
  ClonesF cf1;
  A a("Obiekt a");
  A a1("Obiekt a1");  
  cf1.add(a);
  B b;
  b.x = 7;
  cf1.add(b);
  C c;
  c.v = 3.87;
  cf1.add(c);

  ClonesF cf2;
  cf2.add(a1);

  std::cout << cf1.clone<A>().msg << std::endl;
  std::cout << cf1.clone<B>().x << std::endl;
  std::cout << cf2.clone<A>().msg << std::endl;
  try {    
    cf2.clone<B>();
  } catch( const missing<B>& ) {
    std::cout << "missing type B in the factory cf2" << std::endl;
  }
  
}
/* wynik
Obiekt a
7
Obiekt a1
missing type B in the factory cf2


 */
