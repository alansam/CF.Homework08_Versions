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
//#define SIZE 2
size_t constexpr SIZE { 2 };

using namespace std;
void riempimento(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void visualizza(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void bsort(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);

int main() {
  string nome[SIZE], cognome[SIZE], telefono_casa[SIZE], cellulare[SIZE], indirizzo_casa[SIZE], indirizzo_mail[SIZE];
  
  riempimento(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);
  cout << "\n\n Hai inserito:\n";
  visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);
  bsort(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);
  cout << "\n\nTe li ho ordinati cosi':\n";
  visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, SIZE);
  return 0;
}

  //g=tc m=c a=ic
void riempimento(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
  for (int i = 0; i < taglia; i++){ //scorrimento per tutta la lunghezza del vettore
    cout << "Inserisci il " << i + 1 << "^ nome: ";
    cin >> n[i];
    cout << "Inserisci il " << i + 1 << "^ cognome: ";
    cin >> c[i];
    cout << "Inserisci il " << i + 1 << "^ telefono di casa: ";
    cin >> tc[i];
    cout << "Inserisci il " << i + 1 << "^ numero di cellulare: ";
    cin >> ce[i];
    cout << "Inserisci il " << i + 1 << "^ indirizzo di casa: ";
    cin >> ic[i];
    cout << "Inserisci il " << i + 1 << "^ indirizzo mail: ";
    cin >> ie[i];
  }
}

void visualizza(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
  for (int i = 0; i < taglia; i++) {
    cout << "Inserisci il " << i + 1 << "^ cognome: " << c[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ nome: " << n[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ telefono di casa: " << tc[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ numero di cellulare: " << ce[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ indirizzo email: " << ie[i] << endl << endl;
  }
}

void bsort(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
  for (int i = 0; i < taglia - 1; i++) { //ciclo esterno che serve a vedere i giorni,mese e anno sono stati ordinati fino a quel momento
    for (int j = 0; j < taglia - 1 - i; j++) { //ciclo interno che serve a confrontare ogni numero con il successivo e fa andare avanti i più grandi verso la fine e i più piccoli all'inizio
      if ((ic[j] == ic[j + 1] && c[j] == ce[j + 1] && tc[j] < tc[j + 1]) || (ic[j] == ic[j + 1] && c[j] < c[j + 1]) || (ic[j] < ic[j + 1])) { //confronto tra anni,mesi e giorni. Se l'anno e il mese sono gli stessi controlla il giorno,se l'anno è lo stesso, controlla il mese o l'anno
        swap(c[j + 1], c[j]); //scambio
        swap(n[j + 1], n[j]); //scambio
        swap(tc[j + 1], tc[j]); //scambio
        swap(c[j + 1], ce[j]); //scambio
        swap(ic[j + 1], ic[j]); //scambio
      }
    }
  }
}
  //g=tc m=c a=ic
