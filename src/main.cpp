#include "SSortowanie.hh"
#include "SKolejka_prio.hh"
#include "SKolejka_FIFO.hh"
#include "SElement.hh"

  
int main() {
  // Kolejka przechowująca "otrzymane" pakiety
  Kolejka_FIFO<string> K;

  // Pakiety "przychodzące" w losowej kolejności 
  K.queue(3,"przyjechać w odwiedziny w ");
  K.queue(7,"trudnym czasie, Jan.");
  K.queue(1,"Cześć Anna, co u Ciebie?");
  K.queue(4,"któryś z dni wolnych. Kiedy");
  K.queue(6,"Dużo zdrowia w tym ");
  K.queue(2,"Piszę, ponieważ chciałbym");
  K.queue(5,"mógłbym przyjechać?");

  // Pokazanie zawartości kolejki_FIFO
  cout << "Zawartość kolejki przed uporządkowaniem wiadomości: ";
  K.wyswietl();
  
  
  // Kolejka potrzebna do sortowania 
  Kolejka_Priorytetowa<string> M;

  // Sotrowanie "otrzymanych" wiadomości z wykorzystaniem kolejki priorytetowej 
  Sortowanie_Kolejka_Priorytetowa(K,M);

  // Pokazanie zawartości kolejki_FIFO
  cout << "Zawartość kolejki po uporządkowaniu wiadomości: ";
  K.wyswietl();   
 
  return 1;
}
  
