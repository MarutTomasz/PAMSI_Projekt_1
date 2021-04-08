#ifndef SZABLON_SORTOWANIE
#define SZABLON_SORTOWANIE

#include "SKolejka_prio.hh"
#include "SKolejka_FIFO.hh"
#include "SElement.hh"

template <typename TYP>
void Sortowanie_Kolejka_Priorytetowa(Kolejka_FIFO<TYP> &S, Kolejka_Priorytetowa<TYP> &P){   // Szblon funkcji sortującej 
  Element<TYP>* pom;   // wskaźnik pomocniczy przy przenoszeniu struktur
  cout <<"----------------SORTOWNIAE----------------" << endl << "Zapełnianie kolejki priorytetowej: ";
  while (!S.isEmpty()) {  // Powtarzaj aż kolejka FIFO nie będzie pusta
    pom = S.dequeue(); // Pobierz element z kolejki FIFO
    P.wstaw(pom->getKlucz(),pom->getElement());  // Dodaj element do kolejki priorytetowej
    delete pom;   // Zwolnij pamięć 
    P.wyswietl(); 
  }
  cout << "Opróżnianie kolejki priorytetowej: ";
  while (!P.isEmpty()) {  // Powtarzaj aż kolejka priorytetowa nie będzie pusta
    pom = P.removeMin();  // Pobierz element o najmniejszym priorytecie z kolejki priorytetowej
    S.queue(pom->getKlucz(),pom->getElement());  // Dodaj element do kolejki FIFO
    delete pom;   // Zwolnij pamięć
    P.wyswietl(); 
  }
  
}


#endif
