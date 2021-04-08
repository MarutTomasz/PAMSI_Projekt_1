#ifndef SZABLON_KOLEJKA_PRIORYTETOWA
#define SZABLON_KOLEJKA_PRIORYTETOWA

#include <iomanip>
#include <iostream>
#include "SElement.hh"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

template<typename TYP>
class Kolejka_Priorytetowa {  // Szablon klasy kolejki priorytetowej 
private:
  Element<TYP>* Glowa; // Wskaźnik na dodatkowy węzeł rozpoczynający kolejkę
  Element<TYP>* Ogon; // Wskaźnik na dodatkowy węzeł kończony kolejkę
public:
  Kolejka_Priorytetowa();  // Konstruktor bezparametryczny kolejki priorytetowej
  ~Kolejka_Priorytetowa(); // Destruktor kolejki priorytetowej
  bool isEmpty() const; // Metoda zwracająca: 1 gdy kolejka jest pusta lub 0 w innym wypadku 
  int size() const;  // Metoda zwracająca liczbę przechowywanych elementów
  void wstaw(int K, TYP X);  // Metoda tworząca nowy element kolejki priorytetowej
  Element<TYP>* removeMin(); // Metoda wyciągająca z kolejki element o najmniejszym priorytecie 
  const Element<TYP>* min() const; // Metoda pozwalająca zobaczyć element o najmniejszym priorytecie bez usuwania go z kolejki
  void wyswietl() const; // Metoda wyświetlająca całą zawartość kolejki
};

#endif
