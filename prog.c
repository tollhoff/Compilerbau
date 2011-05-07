/*
 * prog.c -- ein kleines SLPL-Programm
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "utils.h"
#include "slpl.h"


Knoten *konstruiereProgramm(void) {
  return
    Folge(
      Zuweisung(
        "x",
        Summe(
          Literal(5),
          Literal(3))),
      Folge(
        Ausgabe(
          Variable("x")),
        Folge(
          Zuweisung(
            "y",
            Differenz(
              Produkt(
                Literal(7),
                Variable("x")),
              Literal(2))),
          Ausgabe(
            Quotient(
              Variable("y"),
              Literal(2))))));
}
