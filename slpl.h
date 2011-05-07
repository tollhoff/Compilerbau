/*
 * slpl.h -- Baumknoten
 */


#ifndef _SLPL_H_
#define _SLPL_H_


#define KNOTEN_FOLGE		1
#define KNOTEN_ZUWEISUNG	2
#define KNOTEN_AUSGABE		3
#define KNOTEN_LITERAL		4
#define KNOTEN_VARIABLE		5
#define KNOTEN_SUMME		6
#define KNOTEN_DIFFERENZ	7
#define KNOTEN_PRODUKT		8
#define KNOTEN_QUOTIENT		9


typedef struct knoten {
  int typ;
  union {
    struct {
      struct knoten *anweisung1;
      struct knoten *anweisung2;
    } folge;
    struct {
      char *name;
      struct knoten *ausdruck;
    } zuweisung;
    struct {
      struct knoten *ausdruck;
    } ausgabe;
    struct {
      int wert;
    } literal;
    struct {
      char *name;
    } variable;
    struct {
      struct knoten *ausdruck1;
      struct knoten *ausdruck2;
    } summe;
    struct {
      struct knoten *ausdruck1;
      struct knoten *ausdruck2;
    } differenz;
    struct {
      struct knoten *ausdruck1;
      struct knoten *ausdruck2;
    } produkt;
    struct {
      struct knoten *ausdruck1;
      struct knoten *ausdruck2;
    } quotient;
  } u;
} Knoten;


Knoten *Folge(Knoten *anweisung1, Knoten *anweisung2);
Knoten *Zuweisung(char *name, Knoten *ausdruck);
Knoten *Ausgabe(Knoten *ausdruck);
Knoten *Literal(int wert);
Knoten *Variable(char *name);
Knoten *Summe(Knoten *ausdruck1, Knoten *ausdruck2);
Knoten *Differenz(Knoten *ausdruck1, Knoten *ausdruck2);
Knoten *Produkt(Knoten *ausdruck1, Knoten *ausdruck2);
Knoten *Quotient(Knoten *ausdruck1, Knoten *ausdruck2);


#endif /* _SLPL_H_ */
