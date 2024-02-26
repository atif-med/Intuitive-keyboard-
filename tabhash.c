

#include "tabhash.h"



void initializeHashTable(HashTable *hashTab)
{
	hashTab->size			= HASH_SIZE;
    
	hashTab->nbOccupiedEntries	= 0;
	hashTab->nbElements			= 0;
	hashTab->Elements			= (Element **) malloc(hashTab->size * sizeof(Element*));

	for (unsigned int i = 0; i < hashTab->size; i++){
        hashTab->Elements[i] = (Element *) malloc(HASH_SIZEL * sizeof(Element));
    }
		
}




void loadDictionaryFromFile(HashTable* hashTab, const char* dictionaryFileName, char* css)
{
	FILE *fp;
	fp = fopen(dictionaryFileName, "r");
    long long int i =0;
    //char ass[10^20]="";
    //char css[30];
    //scanf("%s",css);
    //printf("%s\n",css);
	if (fp != NULL)
	{
		Element word;

		while (fscanf(fp, "%s %d", word.value,&word.nombre_occurrence ) == 2)
            //printf("%s\n",word.value);
            //i=distanceLevenshtein(word.value,css);
            //printf("%lld\n",i);

			insertElementToHashTable(hashTab, &word, css);
            
            //printf("%lld\n",i);
        
	}
	else printf("File not found.");
	fclose(fp);
}

//a modifier




void insertElementToHashTable(HashTable* hashTab, Element* word, char* mot) 
{
	
    hashTab->nbElements++;
	long int  i = 0; 
    //i=gethashvalue(word->value);
    i=distanceLevenshtein(word->value,mot);
    //printf("Distance entre %s et %s : %ld\n", word->value, mot, distanceLevenshtein(word->value, mot));

    //printf("%ld\n",i);
    

	Element*		elem	= (Element*) malloc(sizeof(Element));

	strcpy(elem->value, word->value);
	elem->nombre_occurrence=word->nombre_occurrence;

	if (hashTab->Elements[i] == NULL)
		hashTab->nbOccupiedEntries++;

	elem->suiv				= hashTab->Elements[i];
	hashTab->Elements[i]	= elem;
}










void loadDictionaryFromFile2(HashTable* hashTab, const char* dictionaryFileName, char* css)
{
	FILE *fp;
	fp = fopen(dictionaryFileName, "r");
    long long int i =0;
    //char ass[10^20]="";
    //char css[30];
    //scanf("%s",css);
    //printf("%s\n",css);
	if (fp != NULL)
	{
		Element word;

		while (fscanf(fp, "%s", word.value) == 1){
            word.nombre_occurrence =1;
            //printf("%s\n",word.value);
            //i=distanceLevenshtein(word.value,css);
            //printf("%lld\n",i);

			insertElementToHashTable2(hashTab, &word, css);
            
            //printf("%lld\n",i);
        }
	}
	else printf("File not found.");
	fclose(fp);
}


void insertElementToHashTable2(HashTable* hashTab, Element* word, char* mot) 
{
	
    hashTab->nbElements++;
	long int  i = 0; 
    //i=gethashvalue(word->value);
    i=distanceLevenshtein(word->value,mot);
    //printf("Distance entre %s et %s : %ld\n", word->value, mot, distanceLevenshtein(word->value, mot));

    //printf("%ld\n",i);
    

	Element*		elem	= (Element*) malloc(sizeof(Element));

	strcpy(elem->value, word->value);
	elem->nombre_occurrence=word->nombre_occurrence;

	if (hashTab->Elements[i] == NULL)
		hashTab->nbOccupiedEntries++;

	elem->suiv				= hashTab->Elements[i];
	hashTab->Elements[i]	= elem;
}




long int distanceLevenshtein(char *mot1, char *mot2) {
    int longueur1 = strlen(mot1);
    int longueur2 = strlen(mot2);
    int distance[longueur1 + 1][longueur2 + 1];
    
    for (int i = 0; i <= longueur1; i++) {
        distance[i][0] = i;
    }
    
    for (int j = 0; j <= longueur2; j++) {
        distance[0][j] = j;
    }
    
    for (int i = 1; i <= longueur1; i++) {
        for (int j = 1; j <= longueur2; j++) {
            int substitution = distance[i - 1][j - 1] + (mot1[i - 1] != mot2[j - 1]);
            int insertion = distance[i][j - 1] + 1;
            int suppression = distance[i - 1][j] + 1;
            distance[i][j] = substitution < insertion ? substitution : insertion;
            distance[i][j] = distance[i][j] < suppression ? distance[i][j] : suppression;
        }
    }
    
    return distance[longueur1][longueur2];
}



char* ShowPersonalDictionnary(HashTable* hashtab){
    char* text;
    char tmp[25];
    text = (char*) malloc(sizeof(char)*10000000000);
    unsigned int i = 0;
    Element *elem;
    elem = (Element*) malloc(sizeof(Element));
    for(int k=0;k<HASH_SIZE;k++){
        if(hashtab->Elements[k]!=NULL){
            elem = hashtab->Elements[k];
            while(elem!=NULL){
                if(elem->nombre_occurrence){
                    strcpy(tmp,elem->value);
                    strcat(tmp,"\n");
                    strcat(text,tmp);
                    //strcpy(tmp,"");
                    i++;
                }
                elem = elem->suiv;
            }
        }
    }
    return text;
}
