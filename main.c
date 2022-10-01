#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COUNT_CHAR 256

char read_lines();

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
    int stop = 0;

    char ch[MAX_COUNT_CHAR] = read_lines();

    for (int i = 0; i < 50; ++i)
    {
        printf("Mot: %s \n", ch[i]);
        int lenght = strlen(ch[i]);
        printf("Longuer du mot: %d \n", lenght);
    }

    return 0;
}

char read_lines()
{
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("Un probleme est survenue a l'ouverture fichier !");
        exit(1);
    }
    char all_ch[MAX_COUNT_CHAR];
    char ch[MAX_COUNT_CHAR];

    for (int i = 0; fgets(ch, MAX_COUNT_CHAR, fp) != NULL; ++i)
    {
        all_ch[i] = ch;
    }

    fclose(fp);

    return all_ch;
}