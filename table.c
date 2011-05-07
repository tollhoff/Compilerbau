/*
 * table.c -- the symbol table
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "utils.h"
#include "table.h"

Tabelle *newtable;

Tabelle *aendereTabelle(Tabelle *tabelle, char *name, int wert) {

	newtable = allocate(sizeof(tabelle));
	newtable->name = name;
	newtable->wert = wert;
	newtable->next = tabelle;
	return (newtable);
}


int sucheWert(Tabelle *tabelle, char *name) {
    while(tabelle) {
	if(strcmp(tabelle->name, name) == 0) {
		return(tabelle->wert);
	} else if(strcmp(newtable->name, name) == 0) {
		return(newtable->wert);
	}
	else {
		return(sucheWert(tabelle->next, name));
	}
    }
}
