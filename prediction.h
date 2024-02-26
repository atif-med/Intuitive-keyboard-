#ifndef GRAPH_H
#define GRAPH_H


#include "tabhash.h"
#include "stdio.h"
#include "stdlib.h"




void fonct_comp(HashTable *hashtab1,const char* dictionaryFileName1,HashTable *hashtab2,const char* dictionaryFileName2,Element *p1,Element *p2,Element *p3,char *css);

void supprimer_mot(const char *nom_fichier,char *mot);
void replace_word_in_file(char* filename);


void afficherListe(Listeelement* liste);

Listeelement* get_proporsition2(HashTable *hashtab,const char* dictionaryFileName, char* css);

void inserermot(Element *vehi, Listeelement *liste);


void printTopStrings(Listeelement* list,Element *p1,Element *p2,Element *p3);
int getLinkedListLength(Listeelement* list);
void concatenerListes(Listeelement *liste1, Listeelement *liste2);
int find_string(Listeelement *list, char *str);

#endif 