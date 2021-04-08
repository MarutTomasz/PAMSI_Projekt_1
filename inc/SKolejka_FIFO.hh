#ifndef SZABLON_KOLEJKA_FIFO
#define SZABLON_KOLEJKA_FIFO

#include <iomanip>
#include <iostream>
#include "SElement.hh"


template<typename TYP>
class Kolejka_FIFO {  // Szablon kolejki FIFO
private:
  Element<TYP>* glowa; // Wskaźnik na pierwszy dodany element 
  Element<TYP>* ogon; // Wskaźnik na ostatni dodany element

public:
  Kolejka_FIFO();  // Konstruktor kolejki FIFO
  bool isEmpty() const;  // Metoda zwracająca: 1 gdy kolejka jest pusta lub 0 w innym wypadku 
  int size() const;  // Metoda zwracająca liczbę przechowywanych elementów
  void queue(int K, TYP X);  // Metoda dodająca element na początek kolejki
  Element<TYP>* dequeue();  // Metoda pobierająca element z końca kolejki
  void wyswietl() const; // Metoda wyświetlająca całą zawartość kolejki
};


#endif
