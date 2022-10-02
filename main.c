#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COUNT_CHAR 256

char read_lines(char *ch);
int random_number(int max);
void show_word(char *ch, int lenght, char char_enter);

/*
    PENDU
    1: fonction qui recupere un mot au hasard dans un fichier
    2: Afficher le premier, dernier caractere du mot choisis
    3: demander a l'utilisateur d'entrez un caractere (verifie si il y en bien un)
    4: regarder si l'occurance est dans le mot choisis par l'ordinateur (strchr(mot, occurence) )
    5: faire une fonction qui ajoute l'occurance au mot est reafficher
    mettre tout ca dans une boucle while jusqu'au au mot est le mme choisis
    (au bout de 10 tentative le joeur a perdu)

*/

int main(void)
{

    char ch[MAX_COUNT_CHAR];       // tableau de caractere qui sera piocher dans le fichier
    char ch_enter[MAX_COUNT_CHAR]; // charactere entrez par l'utilisateur
    read_lines(ch);
    puts(ch);
    // ajouter une fonction qui supprime le retour chariot

    int lenght_word = strlen(ch);
    int stop = 0;
    while (!stop)
    {
        if (strcmp(ch, ch_enter))
        {
            stop = 1;
        }
        else
        {
            puts(ch); 
            fgets(ch_enter, 10, stdin); // FIXME pk il veut pas input
            show_word(ch, lenght_word, ch_enter[0]);
        }
    }

    return 0;
}

void show_word(char *ch, int lenght, char char_enter)
{
    for (int i = 0; i < lenght; ++i)
    {
        // printf("%d", strchr(ch, char_enter));
        if (strchr(ch, char_enter))
        {
        }
    }
}

int random_number(int max)
{
    srand(time(NULL));
    return rand() % max;
}

char read_lines(char *ch)
{
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("Un probleme est survenue a l'ouverture fichier !");
        exit(1);
    }
    int number_rand = random_number(10);

    for (int i = 0; fgets(ch, MAX_COUNT_CHAR, fp) != NULL; ++i)
    {
        if (i == number_rand)
        {
            break;
        }
    }

    fclose(fp);
}