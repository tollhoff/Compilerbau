/*
 * table.h -- the symbol table
 */


#ifndef _TABLE_H_
#define _TABLE_H_


typedef struct tabelle {
  char *name;
  int wert;
  struct tabelle *next;
} Tabelle;


Tabelle *aendereTabelle(Tabelle *tabelle, char *name, int wert);
int sucheWert(Tabelle *tabelle, char *name);


#endif /* _TABLE_H_ */
