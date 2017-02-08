/*********************************************************************
*
* Auteur : Florian Serraille
* Date de création :  18/01/2017
* Dernière modification : 03/11/2016
*
* Bibliothèque dépendente : stdio.h, string.h
*
*********************************************************************/
#ifndef FONCTION_C_INCLUDED
#define FONCTION_C_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/ftc.h"

#ifdef LINUX
#define FLUSH_STDIN __fpurge(stdin)
#endif // LINUX
#ifdef WIN32
#define FLUSH_STDIN fflush(stdin)
#endif // WIN32



/*  Lecture sécurisée du clavier pour string : fgets() + supression du retour chariot + appel de fonction fpurge_stdin() */
void keyboard_secure_string_reading (char *str, int size){
        char *ptr = NULL;
        fgets(str, size, stdin);
        str[size-1] = '\0';
        ptr = strchr(str, '\n');
        if (ptr)
                *ptr = 0; // Detection et remplacement de retour chariot
        else
                FLUSH_STDIN;
}

/* Envoi sur le flot stderr le message d´erreur, le message ne souffre donc pas d une opération de redirection possible */
void error_stderr(char* message){
        fprintf(stderr, "%*s", sizeof(message), message);
}

void obfuscator(const char *wordFrom, char **wordTo){
    int i;

    *wordTo = strdup(wordFrom);

    for(i=0; i<strlen(wordFrom); i++)
        (*wordTo)[i] = '?';
}

int check_letter_and_reveal(const char *wordToFind, char **wordHidden, char letter){
    int i, find = 0;
    for(i=0; i<strlen(wordToFind); i++){
        if(wordToFind[i] == letter || (wordToFind[i]+32) == letter || (wordToFind[i]-32) == letter){
            (*wordHidden)[i] = wordToFind[i];
            find = 1;
        }
    }
    return find;
}


void game(const char *wordToFind, char *wordHidden){
    char letter;

    while (strcmpi(wordToFind,wordHidden)){

        printf("%s\n", wordHidden);

        FLUSH_STDIN;
        scanf("%c",&letter);
        check_letter_and_reveal(wordToFind, &wordHidden, letter);
    }
    printf("%s\n", wordHidden);
}

void rand_word (char **wordReturn, int theme, int lang){
    /* Statements */
    int ch, numNumber = 0, randNumber;
    char word[50], fileName[50];
    FILE *file;
    srand(time(NULL));

    /* Opening file text */
    switch(theme){
        case 4:
            if(lang == 1)
                sprintf(fileName, "libraries\\all_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\all_en.txt");
                else
                    sprintf(fileName, "libraries\\all_fr.txt");
            break;

        case 5:
            if(lang == 1)
                sprintf(fileName, "libraries\\animal_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\animal_en.txt");
                else
                    sprintf(fileName, "libraries\\animal_fr.txt");
            break;

        case 6:
            if(lang == 1)
                sprintf(fileName, "libraries\\geo_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\geo_en.txt");
                else
                    sprintf(fileName, "libraries\\geo_fr.txt");
            break;

        case 7:
            if(lang == 1)
                sprintf(fileName, "libraries\\weapon_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\weapon_en.txt");
                else
                    sprintf(fileName, "libraries\\weapon_fr.txt");
            break;

        case 8:
            if(lang == 1)
                sprintf(fileName, "libraries\\sport_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\sport_en.txt");
                else
                    sprintf(fileName, "libraries\\sport_fr.txt");
            break;

        case 9:
            if(lang == 1)
                sprintf(fileName, "libraries\\history_pt.txt");
            else
                if(lang == 2)
                    sprintf(fileName, "libraries\\history_en.txt");
                else
                    sprintf(fileName, "libraries\\history_fr.txt");
            break;
    }

    file = fopen(fileName, "r");
    if (file == NULL){
        fprintf(stderr, "Le fichier %s n'a pas pu etre ouvert\n", fileName);
        exit(EXIT_FAILURE);
    }

    /* Counting the number of word in file */
    do{
    ch = fgetc(file);
        if (ch == '\n')
            numNumber++;
    } while(ch != EOF);

    /* Seting the selector at the begining */
    rewind(file);

    /* Sorting the number of the word's line */
    randNumber = rand() % numNumber;

    /* Setting the selector to word's line */
    while(randNumber > 0){
        ch = fgetc(file);
        if (ch == '\n')
            randNumber--;
    }

    /* Getting the word */
    fgets(word, 49, file);

    /* Closing file */
    if (fclose(file) == EOF){
        fprintf(stderr, "Erreur lors de la fermeture du flux\n");
        exit(EXIT_FAILURE);
    }

    /* Removing "/n" */
    word[strlen(word) - 1] = '\0';

    /* Copying word to pointor */
    *wordReturn = malloc(strlen(word));
    if(wordReturn == NULL)
        puts("Erro malloc");
    strcpy(*wordReturn, word);
}

#endif // FONCTION_C_INCLUDED
