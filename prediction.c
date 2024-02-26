
#include "prediction.h"






void fonct_comp(HashTable *hashtab1,const char* dictionaryFileName1,HashTable *hashtab2,const char* dictionaryFileName2,Element *p1,Element *p2,Element *p3,char *css){

    //printf("entrez le debut d'un mot\n");
    //char css[30];
    char caract[30];
    //scanf("%s",css);
    int choice;
    int count = 0;
    Listeelement *list;
    Listeelement *list1;
    Listeelement *list2;

    Element *wanted;
    
    list2=get_proporsition2(hashtab1,dictionaryFileName1,css);
    list=get_proporsition2(hashtab1,dictionaryFileName1,css);

    int j=0;
    int v=0;

    j=getLinkedListLength(list);
    //printf("%d\n",j);
    //i c'est g

    if(j<3){
        list1=get_proporsition2(hashtab2,dictionaryFileName2,css);
        concatenerListes(list,list1);
        }

    //v=getLinkedListLength(list2);
    //printf("%d\n",v);
    if(list->tete!=NULL){
        printTopStrings(list,p1,p2,p3);
    }
    
}




void printTopStrings(Listeelement* list,Element *p1,Element *p2,Element *p3) {
    int i, j;
    //Node* current = head;
    Element* head=list->tete;
    Element* current = head;
    Element* topStrings[MAX_OCCURRENCES] = { NULL };

    // Parcourez la liste et recherchez les trois chaînes de caractères ayant le plus grand nombre d'occurrences.
    while (current != NULL) {
        for (i = 0; i < MAX_OCCURRENCES; i++) {
            if (topStrings[i] == NULL || current->nombre_occurrence > topStrings[i]->nombre_occurrence) {
                // Déplacez toutes les chaînes de caractères en dessous de celle actuelle vers le bas.
                for (j = MAX_OCCURRENCES - 1; j > i; j--) {
                    topStrings[j] = topStrings[j - 1];
                }
                // Ajoutez la chaîne de caractères actuelle à la liste.
                topStrings[i] = current;
                break;
            }
        }
        current = current->suiv;
    }

    
    //int j=0;//
    //printf("Les trois chaines de caractere les plus frequentes sont :\n");
    strcpy(p1->value,topStrings[0]->value);
    strcpy(p2->value,topStrings[1]->value);
    strcpy(p3->value,topStrings[2]->value);

}






int getLinkedListLength(Listeelement* list) {
    int length = 0;
    Element* head=list->tete;
    Element* current = head;
    
    while (current != NULL) {
        length++;
        current = current->suiv;
    }
    
    return length;
}

void inserermot(Element *vehi, Listeelement *liste)
{
  // insertion en tete de liste
  vehi->suiv = liste->tete;
  liste->tete = vehi;
}



Listeelement* get_proporsition2(HashTable *hashtab,const char* dictionaryFileName, char* css){

    int i=0;
    //printf("entrez le debut d'un mot\n");
    // char css[30];
    // char caract[30];
    // scanf("%s",css);

    long long int d=0;
    long long int f=0;
    long long int g=0;
    int count=0;

    Listeelement *list = malloc(sizeof(Listeelement));
    list->tete = NULL;
    Element cour;
    Element *new;

    loadDictionaryFromFile2(hashtab, dictionaryFileName, css);


    
    for( int i=0;i<=hashtab->size;i++){

            if (hashtab->Elements[i] != NULL){
                Element *elem = hashtab->Elements[i];
                while(elem!=NULL){

                    //d=gethashvalue(elem->value);
                    //f=gethashvalue(css);
                    //g=trans(d, strlen(css));

                    if(strncmp(elem->value,css,strlen(css))==0 && count<=200){

                        strcpy(cour.value,elem->value);
                        cour.nombre_occurrence=elem->nombre_occurrence;

                        new = (Element *) malloc(sizeof(Element));
                        *new = cour;
                        inserermot(new, list);
                        count++;

                        //ajout a la liste 
                        //et apres quand on aura la liste chainee on affiche les trois avec le plus grand nombre d'occurence

                    }
                    elem=elem->suiv;

                }

            }
    }
    
    return list;

}



void afficherListe(Listeelement* liste) {
    Element* courant = liste->tete;

    while (courant != NULL) {
        printf("%s\n ", courant->value);
        courant = courant->suiv;
    }
    printf("\n");
}



//valid
long long int getHashValue1(char *str) {
    long long int result = 0;
    int sign = 1;

    // Vérifier si le nombre est négatif
    if (*str == '-') {
        sign = -1;
        str++;
    }

    // Convertir chaque caractère en chiffre
    while (*str != '\0') {
        if (!isdigit(*str)) {
            fprintf(stderr, "La chaine de caracteres n'est pas un entier valide.\n");
            exit(EXIT_FAILURE);
        }
        result = result * 10 + (*str - '0');
        str++;
    }

    // Appliquer le signe
    result *= sign;

    return result;
}






void supprimer_mot(const char *nom_fichier,char *mot_a_supprimer) {
    char buffer[BUFSIZ], *ptr;
    // char mot_a_supprimer[30];
    // printf("donner le mot a supprimer");
    // scanf("%s",mot_a_supprimer);

    size_t mot_len = strlen(mot_a_supprimer);
    FILE *f_in, *f_out;

    f_in = fopen(nom_fichier, "r");
    if (f_in == NULL) {
        perror("Erreur d'ouverture de fichier en lecture");
        exit(EXIT_FAILURE);
    }

    f_out = fopen(nom_fichier, "r+");
    if (f_out == NULL) {
        perror("Erreur d'ouverture de fichier en écriture");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFSIZ, f_in) != NULL) {
        ptr = strstr(buffer, mot_a_supprimer);
        while (ptr != NULL) {
            *ptr = '\0';  // remplace le mot par une chaîne vide
            fputs(buffer, f_out);
            ptr = strstr(ptr + mot_len, mot_a_supprimer);
        }
        fputs(buffer, f_out);
    }

    fclose(f_in);
    fclose(f_out);

  
}


void replace_word_in_file(char* filename) {
    FILE* file = fopen(filename, "r+");

    char old_word[40];
    char new_word[40];

    printf("donner le nom que vous voulez modifier\n");
    scanf("%s",old_word);

    printf("donner le nouveau mot");
    scanf("%s",new_word);

    
    
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    size_t old_word_length = strlen(old_word);
    size_t new_word_length = strlen(new_word);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* position = strstr(buffer, old_word);
        if (position != NULL) {
            fseek(file, position - buffer, SEEK_CUR);
            fputs(new_word, file);
            if (old_word_length < new_word_length) {
                for (size_t i = 0; i < old_word_length -  new_word_length; i++) {
                    fputc(' ', file);
                }
            }
        }
    }
    fclose(file);
}

// void ajouterListe(Listeelement *liste1, Listeelement *liste2) {
//     Element *element = liste1->tete;

//     while (element->suiv != NULL) {
//         element = element->suiv;
//     }

//     element->suiv = liste2->tete;
// }
void concatenerListes(Listeelement *liste1, Listeelement *liste2) {
    if (liste1->tete == NULL) {
        // Si la première liste est vide, on la remplace simplement par la deuxième liste
        liste1->tete = liste2->tete;
    } else {
        // Sinon, on parcourt la première liste jusqu'au dernier élément
        Element *element = liste1->tete;
        while (element->suiv != NULL) {
            element = element->suiv;
        }

        // On ajoute ensuite la deuxième liste à la fin de la première liste
        element->suiv = liste2->tete;
    }

    // On réinitialise la deuxième liste pour éviter une erreur de double libération de mémoire
    liste2->tete = NULL;
}

  // afficherListe(list1);
        // Element* head2=list1->tete;
        // Element* curr = head2;
        // while (count<=3 && curr != NULL) {
        //     inserermot(head2, list);
        //     //afficherListe(list);
        //     count++; 
        //     curr = curr->suiv;
        // }


int find_string(Listeelement *list, char *str) {
    Element *head=list->tete;
    while (head != NULL) {
        if (strcmp(head->value, str) == 0) {
            return 1; // La chaîne est trouvée dans la liste
        }
        head = head->suiv;
    }
    return 0; // La chaîne n'est pas trouvée dans la liste
}