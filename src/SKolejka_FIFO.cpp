#include "SKolejka_FIFO.hh"


template<typename TYP>
Kolejka_FIFO<TYP>::Kolejka_FIFO() {
  glowa = NULL; // Brak elementów, pokazujemy w nicość
  ogon = NULL;
}

template<typename TYP>
bool Kolejka_FIFO<TYP>::isEmpty() const {
  if (glowa == NULL)  // Jeśli brak elementu 
    return 1;   // Zwróć że pusto
  return 0;  // Jednak coś jest
}

template<typename TYP>
int Kolejka_FIFO<TYP>::size() const {
  Element<TYP>* pom = glowa;  // Pomocniczy wskaźnik przeszukujący kolejkę 
  int liczba = 0; // Początkowa liczba elementów 
  while (pom != NULL) {  // Powtarzaj aż będziemy pokazywać w nicość
    liczba++; // Zwiększ liczbę elementów
    pom = pom->getNastepny();  // Przesun pomocniczy
  }
  return liczba;  // Zwróć liczbę elementów 
}

template<typename TYP>
void Kolejka_FIFO<TYP>::queue(int K, TYP X) {
  Element<TYP>* wskaznik = new Element<TYP>;  // Stwórz nowy element 
  wskaznik->setNastepny(glowa);  // Niech nowy element pokazuje na obecny początek
  wskaznik->setPoprzedni(NULL);  // Niech od tyłu pokazuje w nicość 
  if (ogon == NULL) // Jeśli dodajemy pierwszy element
    ogon = wskaznik; // Niech pierwszy do wyjścia będzie zapamiętany 
  if (wskaznik->getNastepny() != NULL)  // Jeśli to nie jest pierwszy element 
    wskaznik->getNastepny()->setPoprzedni(wskaznik);   // Ustaw wcześniejszemu wskaźnik na nowy
  glowa = wskaznik;  // Przesun początek kolejki na nowy
  wskaznik->setKlucz(K); // Ustaw priorytet (??)
  wskaznik->setElement(X); // Ustaw element 
}

template<typename TYP>
Element<TYP>* Kolejka_FIFO<TYP>::dequeue() {
  if (this->isEmpty()) {   // Jeśli kolejka pusta
    cerr << "Kolejka pusta. Zwrocono NULL" << endl;
    return NULL;
  }
  Element<TYP>* pom = ogon; // Ustaw wskaźnik pomocniczy na element wychodzący
  ogon = ogon->getPoprzedni();  // Zmień element do wyjścia 
  if (ogon != NULL) // Jeśli jest jakiś element w kolejce 
    ogon->setNastepny(NULL);  // Niech zapommni o poprzedniku
  else  // Jeśli już jest pusto
    glowa = NULL;  // Zapomnij o początku kolejki
  return pom;  // Zwróć element 
}

template<typename TYP>
void Kolejka_FIFO<TYP>::wyswietl() const {
  Element<TYP>* pom = ogon; // Ustaw pomocniczy wskaźnik przeszukujący kolejkę
  cout << endl; // Linijka odstępu na początku
  while(pom != NULL) { // Powtarzaj do końca kolejki
    cout  <<  pom->getElement() << endl;  // Wiadomość 
    pom = pom->getPoprzedni(); // Przesuń się pomocniczym dalej
  }
  cout  << endl; // Linijka odstępu na końcu
}


