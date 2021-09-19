//
//  PhoneBookItem.h
//  CF.Homework08
//
//  Created by Alan Sampson on 9/16/21.
//

#ifndef PhoneBookItem_h
#define PhoneBookItem_h

#include <string>

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

//  MARK: - Implementation
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
  oss << "  indirizzo di casa: " << thing.indirizzo_casa() << '\n';
  oss << "  indirizzo email: " << thing.indirizzo_mail() << '\n';

  return oss;
}

#endif /* PhoneBookItem_h */
