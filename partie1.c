#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 2580
#define MAX_WORD_LENGTH 100
//#define MAX_SIZE_LIGNE 10600


/*typedef struct _element{
    char caract[30];
    int nombre_occur;
    struct _element *next;
}element;

typedef struct{
    element *head;
}node_element;*/



void sortFile(char* inputFile, char* outputFile);
void count_word_occurrences(char *filename);
//void insererVehicule(element *vehi, node_element *liste);
//void afficherListeVehicules(node_element *liste);


//void afficherVehicule(element *vehi);

void sortFile(char* inputFile, char* outputFile) { //on trie les differents caractere par ordre alphabetique
    char buffer[MAX_SIZE];
    char words[MAX_SIZE][MAX_SIZE];
    int count = 0;

    // Open input file
    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Unable to open input file: %s\n", inputFile);
        return;
    }

    // Read words from input file into array
    while (fscanf(inFile, "%s", buffer) != EOF) {
        strcpy(words[count], buffer);
        count++;
    }

    // Close input file
    fclose(inFile);

    // Sort words in array
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_SIZE];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Open output file
    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Unable to open output file: %s\n", outputFile);
        return;
    }

    // Write sorted words to output file
    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%s\n", words[i]);
    }

    // Close output file
    fclose(outFile);
}






void count_word_occurrences(char *filename) {
    char word[MAX_WORD_LENGTH];
    int count = 0;

    element listcaract;
    element *cara;

    FILE *file;
    FILE *fp;
    // déclaration d'un tableau de structures pour stocker les mots et leurs occurrences
    struct word_info {
        char word[MAX_WORD_LENGTH];
        int count;
    } words[MAX_WORD_LENGTH];

    file = fopen(filename, "r");
    fp = fopen("dosscomp.txt", "w");

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.");
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    while (fscanf(file, "%s", word) != EOF) {
        // convertir le mot en minuscule pour éviter les différences de casse
        
        //fprintf(fp, "%s\n", word);
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // chercher si le mot est déjà dans le tableau
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // si le mot n'a pas été trouvé, l'ajouter au tableau
        if (!found) {
            strcpy(words[word_count].word, word);
            words[word_count].count = 1;
            word_count++;
        }
    }

    // afficher les résultats
   // printf("Le fichier contient %d mots différents :\n", word_count);
    for (int i = 0; i < word_count; i++) {
        //printf("'%s' apparaît %d fois.\n", words[i].word, words[i].count);
        //strcpy(listcaract.caract,words[i].word);
        //listcaract.nombre_occur=words[i].count;
        fprintf(fp, "%s %d\n", words[i].word,words[i].count); // on ecrit dans le fichier
        
        //cara= (element*) malloc(sizeof(element));
        //*cara=listcaract;
        //insererVehicule(cara, tab);

    }

    fclose(file);
    fclose(fp);
}





int main() {
    char inputFile[] = "mots_courants.txt";
    char outputFile[] = "output.txt";
    sortFile(inputFile, outputFile);
    //node_element tab;
    //tab.head=NULL;

    count_word_occurrences(inputFile); 
    //afficherListeVehicules(&tab);

    //ecrireFicVehicules("dosscomp.txt", &tab);

    //init_nombre_occur("mots_courants.txt", &tab);
    return 0;
}




