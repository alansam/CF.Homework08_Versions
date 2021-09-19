//
//  hw08.cpp
//  CF.Homework08
//
//  Created by Alan Sampson on 9/16/21.
//
//  @suthor: Alessio Capacchione : https://www.facebook.com/Alessio.Capacchione1919/
//  @see: https://www.facebook.com/groups/340481293551683/posts/886543212278819/
//  @see: https://www.onlinegdb.com/GG4qYePhp?fbclid=IwAR3gKRbumP0yzMirdeRlE4PWLDURwgpnaku9idYAPxQxQZIxBKJKcBwaj8c

/*
 Hello to all. i am creating this program in c ++ on a phone book. I have to do this through function calls with the use of 6 parallel vectors for:
   - First name
   - Last name
   - Home phone
   - Mobile phone
   - HomeAddress
   - Email address
 the functions to be implemented are:
 This entry must leave the entire list in alphabetical order by surname and first name
 View of the entire list
 Research carried out through dichotomous function
 Elimination
 Edit
 All with an option selection menu that allows you to exit the program when the termination option is chosen.
 FOR THE MOMENT I HAVE DONE THIS, COULD SOMEONE KINDLY HELP ME? THANKS →
 */

#include <iostream>
#include <string>
#include <vector>

//#define SIZE 2
size_t constexpr SIZE { 2 };

//using namespace std;

void riempimento(std::vector<std::string> & nome,
                 std::vector<std::string> & cognome,
                 std::vector<std::string> & telefono_casa,
                 std::vector<std::string> & cellulare,
                 std::vector<std::string> & indirizzo_casa,
                 std::vector<std::string> & indirizzo_mail,
                 size_t const taglia);
void visualizza(std::vector<std::string> & nome,
                std::vector<std::string> & cognome,
                std::vector<std::string> & telefono_casa,
                std::vector<std::string> & cellulare,
                std::vector<std::string> & indirizzo_casa,
                std::vector<std::string> & indirizzo_mail,
                size_t const taglia);
void bsort(std::vector<std::string> & nome,
           std::vector<std::string> & cognome,
           std::vector<std::string> & telefono_casa,
           std::vector<std::string> & cellulare,
           std::vector<std::string> & indirizzo_casa,
           std::vector<std::string> & indirizzo_mail,
           size_t const taglia);

int main() {
  std::vector<std::string> nome(SIZE);
  std::vector<std::string> cognome(SIZE);
  std::vector<std::string> telefono_casa(SIZE);
  std::vector<std::string> cellulare(SIZE);
  std::vector<std::string> indirizzo_casa(SIZE);
  std::vector<std::string> indirizzo_mail(SIZE);

  riempimento(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);

  std::cout << "\n\n Hai inserito:\n";
  visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);

  bsort(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);

  std::cout << "\n\nTe li ho ordinati cosi':\n";
  visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);

  return 0;
}

//g=tc m=c a=ic
/*
*  MARK: riempimento()
*/
void riempimento(std::vector<std::string> & nome,
               std::vector<std::string> & cognome,
               std::vector<std::string> & telefono_casa,
               std::vector<std::string> & cellulare,
               std::vector<std::string> & indirizzo_casa,
               std::vector<std::string> & indirizzo_mail,
               size_t const taglia) {
  for (size_t i_ = 0ULL; i_ < taglia; i_++) {
    //scorrimento per tutta la lunghezza del vettore
    std::cout << "Inserisci il " << i_ + 1 << "^ nome: ";
    std::cin >> nome[i_];
    std::cout << "Inserisci il " << i_ + 1 << "^ cognome: ";
    std::cin >> cognome[i_];
    std::cout << "Inserisci il " << i_ + 1 << "^ telefono di casa: ";
    std::cin >> telefono_casa[i_];
    std::cout << "Inserisci il " << i_ + 1 << "^ numero di cellulare: ";
    std::cin >> cellulare[i_];
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo di casa: ";
    std::cin >> indirizzo_casa[i_];
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo mail: ";
    std::cin >> indirizzo_mail[i_];
  }
}

/*
*  MARK: visualizza()
*/
void visualizza(std::vector<std::string> & nome,
              std::vector<std::string> & cognome,
              std::vector<std::string> & telefono_casa,
              std::vector<std::string> & cellulare,
              std::vector<std::string> & indirizzo_casa,
              std::vector<std::string> & indirizzo_mail,
              size_t const taglia) {
  for (size_t i_ = 0ULL; i_ < taglia; i_++) {
    std::cout << "Inserisci il " << i_ + 1 << "^ cognome: " << cognome[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ nome: " << nome[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ telefono di casa: " << telefono_casa[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ numero di cellulare: " << cellulare[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo casa: " << indirizzo_casa[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo email: " << indirizzo_mail[i_] << '\n';
    std::cout << std::endl;
  }
}

/*
*  MARK: bsort()
*/
void bsort(std::vector<std::string> & nome,
         std::vector<std::string> & cognome,
         std::vector<std::string> & telefono_casa,
         std::vector<std::string> & cellulare,
         std::vector<std::string> & indirizzo_casa,
         std::vector<std::string> & indirizzo_mail,
         size_t const taglia) {
  for (size_t i_ = 0ULL; i_ < taglia - 1; i_++) {
    //ciclo esterno che serve a vedere i giorni,mese e anno sono stati ordinati fino a quel momento
    for (size_t j_ = 0; j_ < taglia - 1 - i_; j_++) {
      //ciclo interno che serve a confrontare ogni numero con il successivo e fa andare avanti i più grandi verso la fine e i più piccoli all'inizio
      /*
       *  doesn't conform to spec.
      if ((indirizzo_casa[j_] == indirizzo_casa[j_ + 1] && cognome[j_] == cellulare[j_ + 1] && telefono_casa[j_] < telefono_casa[j_ + 1]) || (indirizzo_casa[j_] == indirizzo_casa[j_ + 1] && cognome[j_] < cognome[j_ + 1]) || (indirizzo_casa[j_] < indirizzo_casa[j_ + 1])) {
       */
      if (nome[j_] > nome[j_ + 1] ||
          (nome[j_] == nome[j_ + 1] && cognome[j_] > cognome[j_ + 1])) {
        //confronto tra anni,mesi e giorni. Se l'anno e il mese sono gli stessi controlla il giorno,se l'anno è lo stesso, controlla il mese o l'anno
        std::swap(cognome[j_ + 1], cognome[j_]);   //scambio
        std::swap(nome[j_ + 1], nome[j_]);   //scambio
        std::swap(telefono_casa[j_ + 1], telefono_casa[j_]); //scambio
        std::swap(cellulare[j_ + 1], cellulare[j_]);  //scambio
        std::swap(indirizzo_casa[j_ + 1], indirizzo_casa[j_]); //scambio
        std::swap(indirizzo_mail[j_ + 1], indirizzo_mail[j_]); //scambio
      }
    }
  }
}
//g=tc m=c a=ic
