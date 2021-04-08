#ifndef SZABLON_ELEMENT
#define SZABLON_ELEMENT

#include <iomanip>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cerr;


template<typename TYP>
class Element {   // Szablon klasa definiujący węzeł kolejki priorytetowej i FIFO
private:
  TYP elem;    // Miejsce na przechowywaną daną
  int klucz;   // Miejsce na priorytet 
  Element<TYP>* nastepny;   // wskaźnik na element kolejki, który został dodany wcześniej
  Element<TYP>* poprzedni;  // wzkaźnik na element kolejki, który został dodany później
public:
  // Mrtody pobierające wartości przechowywane przez clasę
  TYP getElement() {return elem;}   
  Element<TYP>* getNastepny() {return nastepny;}
  Element<TYP>* getPoprzedni() {return poprzedni;}
  int getKlucz() {return klucz;}

  // Metody ustanawiające nowe wartości, które ma przechowywać struktura 
  void setElement(TYP nowyElem) {elem = nowyElem;}
  void setKlucz(int nowyKlucz) {klucz = nowyKlucz;}
  void setNastepny(Element<TYP>* nowyNastepny) {nastepny = nowyNastepny;}
  void setPoprzedni(Element<TYP>* nowyPoprzedni) {poprzedni = nowyPoprzedni;}
};

#endif
