/*
 * main.c -- an interpreter for SLPL
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "utils.h"
#include "slpl.h"
#include "table.h"
#include "prog.h"
Tabelle tabelle;

int interpretAusdruck(Knoten *baum, Tabelle *tabelle);

void zeigeBaum(Knoten *baum) {
	switch(baum->typ) {
	case KNOTEN_FOLGE: printf("Folge (\n"); zeigeBaum(baum->u.folge.anweisung1); zeigeBaum(baum->u.folge.anweisung2); printf(")\n"); break;
	case KNOTEN_ZUWEISUNG: printf("Zuweisung(\n\"%s\", \n",baum->u.zuweisung.name); zeigeBaum(baum->u.zuweisung.ausdruck); printf(")\n"); break;
	case KNOTEN_AUSGABE: printf("Ausgabe(\n");zeigeBaum(baum->u.ausgabe.ausdruck); break;
	case KNOTEN_LITERAL: printf("Literal(%i)\n",baum->u.literal.wert); break;
	case KNOTEN_VARIABLE: printf("Variable(%s)\n",baum->u.variable.name); break;
	case KNOTEN_SUMME: printf("Summe(\n"); zeigeBaum(baum->u.summe.ausdruck1); zeigeBaum(baum->u.summe.ausdruck2); printf(")\n"); break;
	case KNOTEN_DIFFERENZ: printf("Differenz(\n");zeigeBaum(baum->u.differenz.ausdruck1); zeigeBaum(baum->u.differenz.ausdruck2); printf(")\n"); break;
	case KNOTEN_PRODUKT: printf("Produkt(\n");zeigeBaum(baum->u.produkt.ausdruck1); zeigeBaum(baum->u.produkt.ausdruck2); printf(")\n"); break;
	case KNOTEN_QUOTIENT: printf("Quotient(\n");zeigeBaum(baum->u.quotient.ausdruck1); zeigeBaum(baum->u.quotient.ausdruck2); printf(")\n"); break;
	}
}

Tabelle *interpretAnweisung(Knoten *baum, Tabelle *tabelle) {

    switch (baum->typ) {
        case KNOTEN_FOLGE: printf("fol "); interpretAnweisung(baum->u.folge.anweisung1, tabelle); interpretAnweisung(baum->u.folge.anweisung2, tabelle); break;
        default: interpretAusdruck(baum, tabelle); return NULL;break;
    }
}

int interpretAusdruck(Knoten *baum, Tabelle *tabelle) {

    switch (baum->typ) {
            case KNOTEN_ZUWEISUNG: printf("zuw "); aendereTabelle(tabelle, baum->u.zuweisung.name, interpretAusdruck(baum->u.zuweisung.ausdruck, tabelle)); break;
            case KNOTEN_LITERAL: printf("lit("); printf("%i) ",baum->u.literal.wert); return baum->u.literal.wert; break;
            case KNOTEN_SUMME: printf("sum("); return interpretAusdruck(baum->u.summe.ausdruck1, tabelle) + interpretAusdruck(baum->u.summe.ausdruck2, tabelle); break;
            case KNOTEN_DIFFERENZ: printf("dif "); return interpretAusdruck(baum->u.differenz.ausdruck1, tabelle) - interpretAusdruck(baum->u.differenz.ausdruck2, tabelle); break;
            case KNOTEN_PRODUKT: printf("pro "); return interpretAusdruck(baum->u.produkt.ausdruck1, tabelle) * interpretAusdruck(baum->u.produkt.ausdruck2, tabelle); break;
            case KNOTEN_QUOTIENT: printf("quo "); return interpretAusdruck(baum->u.quotient.ausdruck1, tabelle) / interpretAusdruck(baum->u.quotient.ausdruck2, tabelle); break;
            case KNOTEN_AUSGABE: printf("AUSGABE "); printf("%i ", sucheWert(tabelle, baum->u.zuweisung.name)); break;
            case KNOTEN_VARIABLE: return sucheWert(tabelle, baum->u.variable.name) ;break;
            default: interpretAnweisung(baum, tabelle);return -1;break;
    }
}

void interpretiere(Knoten *baum) {
    
        switch (baum->typ) {
            case KNOTEN_FOLGE: printf("fol "); interpretAnweisung(baum->u.folge.anweisung1, &tabelle); interpretAnweisung(baum->u.folge.anweisung2, &tabelle); break;
            default: interpretAusdruck(baum, &tabelle); break;
            
        }
    
}


int main(void) {
  Knoten *programm;

  programm = konstruiereProgramm();
  //zeigeBaum(programm);
  printf("\n");
  interpretiere(programm);
  printf("\n");

  return 0;
}
