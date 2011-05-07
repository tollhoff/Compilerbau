/*
 * slpl.c -- Baumknoten
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "utils.h"
#include "slpl.h"


Knoten *Folge(Knoten *anweisung1, Knoten *anweisung2) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_FOLGE;
  knoten->u.folge.anweisung1 = anweisung1;
  knoten->u.folge.anweisung2 = anweisung2;
  return knoten;
}


Knoten *Zuweisung(char *name, Knoten *ausdruck) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_ZUWEISUNG;
  knoten->u.zuweisung.name = name;
  knoten->u.zuweisung.ausdruck = ausdruck;
  return knoten;
}


Knoten *Ausgabe(Knoten *ausdruck) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_AUSGABE;
  knoten->u.ausgabe.ausdruck = ausdruck;
  return knoten;
}


Knoten *Literal(int wert) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_LITERAL;
  knoten->u.literal.wert = wert;
  return knoten;
}


Knoten *Variable(char *name) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_VARIABLE;
  knoten->u.variable.name = name;
  return knoten;
}


Knoten *Summe(Knoten *ausdruck1, Knoten *ausdruck2) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_SUMME;
  knoten->u.summe.ausdruck1 = ausdruck1;
  knoten->u.summe.ausdruck2 = ausdruck2;
  return knoten;
}


Knoten *Differenz(Knoten *ausdruck1, Knoten *ausdruck2) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_DIFFERENZ;
  knoten->u.differenz.ausdruck1 = ausdruck1;
  knoten->u.differenz.ausdruck2 = ausdruck2;
  return knoten;
}


Knoten *Produkt(Knoten *ausdruck1, Knoten *ausdruck2) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_PRODUKT;
  knoten->u.produkt.ausdruck1 = ausdruck1;
  knoten->u.produkt.ausdruck2 = ausdruck2;
  return knoten;
}


Knoten *Quotient(Knoten *ausdruck1, Knoten *ausdruck2) {
  Knoten *knoten;

  knoten = (Knoten *) allocate(sizeof(Knoten));
  knoten->typ = KNOTEN_QUOTIENT;
  knoten->u.quotient.ausdruck1 = ausdruck1;
  knoten->u.quotient.ausdruck2 = ausdruck2;
  return knoten;
}
