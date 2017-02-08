#ifndef INTRO_C_INCLUDED
#define INTRO_C_INCLUDED

#include <SDL.h>
//#include <SDL_Image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "../headers/ftc.h"
#include "../headers/ftc_SDL.h"
#include "../headers/intro.h"

#define TITLE_TEXT "HANGMAN"
#define WHITE_COLOR {255,255,255,255}
#define PTSIZE_TITLE_MENU 60
#define FONTPATH_MENU "fonts\\friday13\\Friday13v12.ttf"
#define INTRO_TIME 2500

void intro(SDL_Window *window, SDL_Renderer *renderer){

    SDL_Texture *hang = NULL, *title_text = NULL;
    SDL_Color white = WHITE_COLOR;
    SDL_Rect title_positon;

    title_positon.x = 300;
    title_positon.y = 450;

    title_text = text_texture(FONTPATH_MENU, PTSIZE_TITLE_MENU, TITLE_TEXT, white, renderer);

    hang = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("pictures\\hang.bmp"));
    if (hang == NULL)
        fprintf(stderr, "Error SDL_CreateTextureFromSurface\n");

    show_texture(renderer, hang, NULL , NULL);
    show_texture(renderer, title_text, NULL, &title_positon);

    SDL_RenderPresent(renderer);
    SDL_Delay(INTRO_TIME);

    SDL_DestroyTexture(hang);
    SDL_DestroyTexture(title_text);
}

#endif // INTRO_C_INCLUDED
