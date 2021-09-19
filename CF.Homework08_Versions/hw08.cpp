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
#include <algorithm>

//  MARK: - Constants
//#define SIZE 2
size_t constexpr SIZE { 2 };

//using namespace std;
using namespace std::literals::string_literals;

//  MARK: - Definitions
/*
 *  MARK: Class PhoneBookItem
 */
class PhoneBookItem {
public:
  PhoneBookItem(std::string nome = ""s,
       std::string cognome = ""s,
       std::string telefono_casa = ""s,
       std::string cellulare = ""s,
       std::string indirizzo_casa = ""s,
       std::string indirizzo_mail = ""s) :
  nome_ { nome }, cognome_ { cognome },
  telefono_casa_ { telefono_casa }, cellulare_ { cellulare },
  indirizzo_casa_ { indirizzo_casa }, indirizzo_mail_ { indirizzo_mail } {}
  ~PhoneBookItem() = default;

  std::string nome(void) const { return nome_; }
  std::string cognome(void) const { return cognome_; }
  std::string telefono_casa(void) const { return telefono_casa_; }
  std::string cellulare(void) const { return cellulare_; };
  std::string indirizzo_casa(void) const { return indirizzo_casa_; }
  std::string indirizzo_mail(void) const { return indirizzo_mail_; }

  std::string nome(std::string nome) {
    return nome_ = nome;
  }
  std::string cognome(std::string cognome) {
    return cognome_ = cognome;
  }
  std::string telefono_casa(std::string telefono_casa) {
    return telefono_casa_ = telefono_casa;
  }
  std::string cellulare(std::string cellulare) {
    return cellulare_ = cellulare;
  };
  std::string indirizzo_casa(std::string indirizzo_casa) {
    return indirizzo_casa_ = indirizzo_casa;
  }
  std::string indirizzo_mail(std::string indirizzo_mail) {
    return indirizzo_mail_ = indirizzo_mail;
  }

  bool operator <(PhoneBookItem const & that) const;
  bool operator >(PhoneBookItem const & that) const;
  bool operator >=(PhoneBookItem const & that) const { return !(*this < that); }
  bool operator <=(PhoneBookItem const & that) const { return !(*this > that); }
  bool operator ==(PhoneBookItem const & that) const { return !(*this > that) && !(*this < that); }
  bool operator !=(PhoneBookItem const & that) const { return !(*this == that); }

  friend
  std::ostream & operator <<(std::ostream & oss, PhoneBookItem const & thing);

private:
  std::string nome_;
  std::string cognome_;
  std::string telefono_casa_;
  std::string cellulare_;
  std::string indirizzo_casa_;
  std::string indirizzo_mail_;
};

#ifdef LOTS_OF_VECTORS
void riempimento(std::vector<std::string> nome,
                 std::vector<std::string> cognome,
                 std::vector<std::string> telefono_casa,
                 std::vector<std::string> cellulare,
                 std::vector<std::string> indirizzo_casa,
                 std::vector<std::string> indirizzo_mail,
                 size_t taglia);
void visualizza(std::vector<std::string> nome,
                std::vector<std::string> cognome,
                std::vector<std::string> telefono_casa,
                std::vector<std::string> cellulare,
                std::vector<std::string> indirizzo_casa,
                std::vector<std::string> indirizzo_mail,
                size_t taglia);
void bsort(std::vector<std::string> nome,
           std::vector<std::string> cognome,
           std::vector<std::string> telefono_casa,
           std::vector<std::string> cellulare,
           std::vector<std::string> indirizzo_casa,
           std::vector<std::string> indirizzo_mail,
           size_t taglia);
#endif  /* LOTS_OF_VECTORS */

#ifndef LOTS_OF_VECTORS
void riempimento_eex(std::vector<PhoneBookItem> & items, size_t const taglia);
void visualizza_eex(std::vector<PhoneBookItem> const & items);
#endif  /* LOTS_OF_VECTORS */

//  MARK: - Implementation
#ifndef LOTS_OF_VECTORS
/*
 *  MARK: PhoneBookItem::operator <()
 */
inline
bool PhoneBookItem::operator <(PhoneBookItem const & that) const {
  bool lt;
  if (nome() < that.nome()) {
    lt = true;
  }
  else if (nome() == that.nome()) {
    if (cognome() < that.cognome()) {
      lt = true;
    }
    else {
      lt = false;
    }
  }
  else {
    lt = false;
  }

  return lt;
}

/*
 *  MARK: PhoneBookItem::operator >()
 */
inline
bool PhoneBookItem::operator >(PhoneBookItem const & that) const {
  bool gt;
  if (nome() > that.nome()) {
    gt = true;
  }
  else if (nome() == that.nome()) {
    if (cognome() > that.cognome()) {
      gt = true;
    }
    else {
      gt = false;
    }
  }
  else {
    gt = false;
  }

  return gt;
}

/*
 *  MARK: operator <<()
 */
inline
std::ostream & operator <<(std::ostream & oss, PhoneBookItem const & thing) {
  oss << "  cognome: " << thing.cognome() << '\n';
  oss << "  nome: " << thing.nome() << '\n';
  oss << "  telefono di casa: " << thing.telefono_casa() << '\n';
  oss << "  numero di cellulare: " << thing.cellulare() << '\n';
  oss << "  indirizzo email: " << thing.indirizzo_mail() << '\n';

  return oss;
}
#endif  /* LOTS_OF_VECTORS */

/*
 *  MARK: main()
 */
int main() {
#ifdef LOTS_OF_VECTORS
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
#else
  std::vector<PhoneBookItem> items;

  riempimento_eex(items, SIZE);

  std::cout << "\n\n Hai inserito:\n";
  visualizza_eex(items);

  std::sort(items.begin(), items.end(), std::less<PhoneBookItem>());

  std::cout << "\n\nTe li ho ordinati cosi':\n";
  visualizza_eex(items);

  std::sort(items.begin(), items.end(), std::greater<PhoneBookItem>());

  std::cout << "\n\nTe li ho ordinati cosi':\n";
  visualizza_eex(items);
#endif /* LOTS_OF_VECTORS */

  return 0;
}

#ifdef LOTS_OF_VECTORS
  //g=tc m=c a=ic
/*
 *  MARK: riempimento()
 */
void riempimento(std::vector<std::string> nome,
                 std::vector<std::string> cognome,
                 std::vector<std::string> telefono_casa,
                 std::vector<std::string> cellulare,
                 std::vector<std::string> indirizzo_casa,
                 std::vector<std::string> indirizzo_mail,
                 size_t taglia) {
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
void visualizza(std::vector<std::string> nome,
                std::vector<std::string> cognome,
                std::vector<std::string> telefono_casa,
                std::vector<std::string> cellulare,
                std::vector<std::string> indirizzo_casa,
                std::vector<std::string> indirizzo_mail,
                size_t taglia) {
  for (size_t i_ = 0ULL; i_ < taglia; i_++) {
    std::cout << "Inserisci il " << i_ + 1 << "^ cognome: " << cognome[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ nome: " << nome[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ telefono di casa: " << telefono_casa[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ numero di cellulare: " << cellulare[i_] << '\n';
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo email: " << indirizzo_mail[i_] << '\n';
    std::cout << std::endl;
  }
}

/*
 *  MARK: bsort()
 */
void bsort(std::vector<std::string> nome,
           std::vector<std::string> cognome,
           std::vector<std::string> telefono_casa,
           std::vector<std::string> cellulare,
           std::vector<std::string> indirizzo_casa,
           std::vector<std::string> indirizzo_mail,
           size_t taglia) {
  for (size_t i_ = 0ULL; i_ < taglia - 1; i_++) {
    //ciclo esterno che serve a vedere i giorni,mese e anno sono stati ordinati fino a quel momento
    for (size_t j_ = 0; j_ < taglia - 1 - i_; j_++) {
      //ciclo interno che serve a confrontare ogni numero con il successivo e fa andare avanti i più grandi verso la fine e i più piccoli all'inizio
      if ((indirizzo_casa[j_] == indirizzo_casa[j_ + 1] && cognome[j_] == cellulare[j_ + 1] && telefono_casa[j_] < telefono_casa[j_ + 1]) || (indirizzo_casa[j_] == indirizzo_casa[j_ + 1] && cognome[j_] < cognome[j_ + 1]) || (indirizzo_casa[j_] < indirizzo_casa[j_ + 1])) {
        //confronto tra anni,mesi e giorni. Se l'anno e il mese sono gli stessi controlla il giorno,se l'anno è lo stesso, controlla il mese o l'anno
        std::swap(cognome[j_ + 1], cognome[j_]);   //scambio
        std::swap(nome[j_ + 1], nome[j_]);   //scambio
        std::swap(telefono_casa[j_ + 1], telefono_casa[j_]); //scambio
        std::swap(cognome[j_ + 1], cellulare[j_]);  //scambio
        std::swap(indirizzo_casa[j_ + 1], indirizzo_casa[j_]); //scambio
      }
    }
  }
}
  //g=tc m=c a=ic

#else

/*
 *  MARK: riempimento_eex()
 */
void riempimento_eex(std::vector<PhoneBookItem> & items, size_t const taglia) {
  for (size_t i_ = 0ULL; i_ < taglia; ++i_) {
    std::string nome;
    std::string cognome;
    std::string telefono_casa;
    std::string cellulare;
    std::string indirizzo_casa;
    std::string indirizzo_mail;
    //scorrimento per tutta la lunghezza del vettore
    std::cout << "Inserisci il " << i_ + 1 << "^ nome: ";
    std::cin >> nome;
    std::cout << "Inserisci il " << i_ + 1 << "^ cognome: ";
    std::cin >> cognome;
    std::cout << "Inserisci il " << i_ + 1 << "^ telefono di casa: ";
    std::cin >> telefono_casa;
    std::cout << "Inserisci il " << i_ + 1 << "^ numero di cellulare: ";
    std::cin >> cellulare;
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo di casa: ";
    std::cin >> indirizzo_casa;
    std::cout << "Inserisci il " << i_ + 1 << "^ indirizzo mail: ";
    std::cin >> indirizzo_mail;

    auto item = PhoneBookItem(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail);

    items.push_back(item);
  }
}

/*
 *  MARK: visualizza_eex()
 */
void visualizza_eex(std::vector<PhoneBookItem> const & items) {
  for (size_t i_ = 0ULL; i_ < items.size(); ++i_) {
    std::cout << "Inserisci il " << i_ + 1 << '^' << '\n' << items[i_];
    std::cout << std::endl;
  }
}
#endif  /* LOTS_OF_VECTORS */
