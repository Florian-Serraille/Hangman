#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
//#include <SDL_Image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "../headers/ftc.h"
#include "../headers/ftc_SDL.h"
#include "../headers/menu.h"
#include "../headers/intro.h"
#include "../headers/game.h"

/* Macro */
#define WORD "NINA"

int main(int argc, char *argv[]){

    /* Declaração variaveis */
    char *word = NULL, *hiddenWord = NULL;
    int *settings, theme, lang;

    /* Declaração variáveis SDL */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Initialização das variáveis SDL */
    init_SDL(&window, &renderer);

    intro(window, renderer);

    /* Menu e parametragens do jogo */
    settings = menu(window, renderer);
    theme = settings[0];
    lang = settings[1];

    /* Acquisisção da palavra secreta */
    rand_word(&word, theme, lang);

    /* Creating hidden word */
    obfuscator(word, &hiddenWord);

    game_SDL(window, renderer, word, hiddenWord);

    /* Free das variáveis SDL */
    quit_SDL(&window, &renderer);

    return EXIT_SUCCESS;
}
