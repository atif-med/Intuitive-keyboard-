#ifndef TABHASH_H
#define TABHASH_H



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "ctype.h"
#include "math.h"

#define HASH_SIZE    50
#define HASH_SIZEL    444444
#define MAX_WORD_LENGHT 30		/* Maximum word length */
#define HASH_SIZE2		37987	/* Prime number */
#define BASE			128
#define MAX_OCCURRENCES 3



typedef struct HashNode {
    char key[4];
    char value[30];
    int nombre_occurrence;
    struct HashNode *suiv;
}Element;


typedef struct _hashTable
{
	long long int	size;
	unsigned int	nbOccupiedEntries;
	unsigned int	nbElements;
	Element		**Elements;
} HashTable;

typedef struct
{
  Element *tete;
} Listeelement;






void initializeHashTable(HashTable *hashTab);
void insertElementToHashTable(HashTable* hashTab, Element* word, char* mot);
void loadDictionaryFromFile(HashTable* hashTab, const char* dictionaryFileName, char* css);
void loadDictionaryFromFile2(HashTable* hashTab, const char* dictionaryFileName, char*css);
void insertElementToHashTable2(HashTable* hashTab, Element* word, char* mot);
long int distanceLevenshtein(char *mot1, char *mot2);
char* ShowPersonalDictionnary(HashTable* hashtab);
#endif 