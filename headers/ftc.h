#ifndef FTC_H_INCLUDED
#define FTC_H_INCLUDED

/*********************************************************************
*
* Auteur : Florian Serraille
* Date de cr�ation :  18/01/2017
* Derni�re modification : 22/10/2016
*
* Biblioth�que d�pendente : stdio.h, string.h
*
*********************************************************************/

/*  Lecture s�curis�e du clavier : fgets() + supression du retour chariot + fflush(stdin) */
void keyboard_secure_string_reading (char *str, int size);
/* Envoi sur le flot stderr le message d�erreur, le message ne souffre donc pas d une op�ration de redirection possible */
void error_stderr(char* message);
void obfuscator(const char *wordFrom, char **wordTo);
void game(const char *wordToFind, char *wordHidden);
int check_letter_and_reveal(const char *wordToFind, char **wordHidden, char letter);
void rand_word (char **wordReturn, int theme, int lang);

#endif // FTC_H_INCLUDED
