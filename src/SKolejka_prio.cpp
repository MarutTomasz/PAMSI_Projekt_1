#include "SKolejka_prio.hh"


template<typename TYP>
Kolejka_Priorytetowa<TYP>::Kolejka_Priorytetowa() {
  Glowa = new Element<TYP>;  // Dodanie węzła ropoczynającego kolejkę
  Ogon = new Element<TYP>;  // Dodanie węzła kończonceko kolejkę
  Glowa->setNastepny(Ogon);  // Ustawianie wskaźnika na koniec kolejki
  Ogon->setPoprzedni(Glowa);  // Ustawianie wskaźnika na początek kolejki 
}

template<typename TYP>
Kolejka_Priorytetowa<TYP>::~Kolejka_Priorytetowa() {
  delete Glowa;  // Zwalnianie pamięci 
  delete Ogon;  // Zwalnianie pamięci
}

template<typename TYP>
bool Kolejka_Priorytetowa<TYP>::isEmpty() const {
  if (Glowa->getNastepny() == Ogon) // Jeśli Początek pokazuje na koniec
    return 1; // Kolejka pusta
  return 0;  // Coś jest w kolejce
}

template<typename TYP>
int Kolejka_Priorytetowa<TYP>::size() const {
  Element<TYP>* pom = Glowa->getNastepny();  // ustaw pomocniczy wskaźnik na element wskazywany przez początek kolejki
  int liczba = 0;  // Ustaw liczbę elementów
  while (pom != Ogon) {  // Jeśli osiągnięto koniec kolejki
    liczba++;  // Zwiększ liczbę elementów 
    pom = pom->getNastepny();  // Przesun wskaźnik pomocniczy dalej
  }
  return liczba;  // Zwróć liczbę elemntów 
  
}

template<typename TYP>
void Kolejka_Priorytetowa<TYP>::wstaw(int K, TYP X) {
  Element<TYP>* wskaznik = new Element<TYP>;  // Stwórz nowy element kolejki
  if (Glowa->getNastepny() == Ogon){  // Jeśli to będzie pierwszy element
    Ogon->setPoprzedni(wskaznik);  // Niech koniec kolejki na niego pokazuje
    Glowa->setNastepny(wskaznik);  // Niech początek koleki na niego pokazuje
    wskaznik->setNastepny(Ogon);  // Niech nowy element pokazuje na koniec
    wskaznik->setPoprzedni(Glowa); // Niech nowy element pokazuje na początek
  }
  else {   // Jeśli jest już jakiś element 
    wskaznik->setNastepny(Glowa->getNastepny());  // Niech nowy element pokazuje na pierwszy w kolejce 
    wskaznik->getNastepny()->setPoprzedni(wskaznik);  // Niech stary pierwszy element pokazuje na nowy
    Glowa->setNastepny(wskaznik);  // Niech głowa pokazuje na nowy element 
    wskaznik->setPoprzedni(Glowa);  // Niech nowy kolazuje na głowę
  }
  wskaznik->setKlucz(K);  // Ustaw wartość priorytetu
  wskaznik->setElement(X);  // Ustaw przechowywaną daną 
}

template<typename TYP>
Element<TYP>* Kolejka_Priorytetowa<TYP>::removeMin() {
  if (this->isEmpty()) {   // Jeśli kojeka pusta 
    cout << "Kolejka pusta. Zwrócono NULL" << endl;
    return NULL;
  }
  Element<TYP>* pom = Glowa->getNastepny()->getNastepny();  // Ustaw pomocniczy wskaźnik przeszukujący kolejkę
  Element<TYP>* minimalny = Glowa->getNastepny(); // Dodaj wskaźnik przechowyujący najmniejszy priorytet
  while(pom != Ogon) {  // Powtarzaj do końca kolejki
    if (pom->getKlucz() < minimalny->getKlucz())   // Jeśli priorytet pomocniczego jest mniejszt niż obecnie najmniejszy
      minimalny = pom;   // Zastąp wskaźnik w minimalnym
    pom = pom->getNastepny();  // Przesuń się pomocniczym dalej
  } 
  minimalny->getNastepny()->setPoprzedni(minimalny->getPoprzedni()); // Zmien wskaźnik w następnym elemencie, żeby nie zrobić dziury w kolejce 
  minimalny->getPoprzedni()->setNastepny(minimalny->getNastepny());  // Zmień wskaźnik w poprzednim elemencie, żeby nie zrobić dziury w kolejce
  
  minimalny->setPoprzedni(NULL); // Niech element zapomni o kolejce kolejce 
  minimalny->setNastepny(NULL);  
  
  return minimalny; // zwróc wskaźnik do elementu z najmniejszym piorytetem 
}

template<typename TYP>
const Element<TYP>* Kolejka_Priorytetowa<TYP>::min() const{
  if (this->isEmpty()){    // Jeśli kojeka pusta 
    cout << "Kolejka pusta. Zwrócono NULL" << endl;
    return NULL;
  }
  Element<TYP>* pom = Glowa->getNastepny()->getNastepny();  // Ustaw pomocniczy wskaźnik przeszukujący kolejkę
  Element<TYP>* minimalny = Glowa->getNastepny(); // Dodaj wskaźnik przechowujący najmniejszy priorytet
  while(pom != Ogon) { // Powtarzaj do końca kolejki
    if (pom->getKlucz() < minimalny->getKlucz()) // Jeśli priorytet pomocniczego jest mniejszt niż obecnie najmniejszy
      minimalny = pom;   // Zastąp wskaźnik w minimalnym
    pom = pom->getNastepny(); // Przesuń się pomocniczym dalej
  }
  return minimalny;  // zwróc wskaźnik do elementu z najmniejszym piorytetem   
}

template<typename TYP>
void Kolejka_Priorytetowa<TYP>::wyswietl() const {
  Element<TYP>* pom = Glowa->getNastepny(); // Ustaw pomocniczy wskaźnik przeszukujący kolejkę
  cout << endl; // Linijka odstępu na początku
  while(pom != Ogon) { // Powtarzaj do końca kolejki
    cout  << "Wiadomość o treści: - " << pom->getElement() << " - i priorytecie " << pom->getKlucz() << endl;  // Wiadomość 
    pom = pom->getNastepny(); // Przesuń się pomocniczym dalej
  }
  cout  << endl; // Linijka odstępu na końcu
}
