#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/* MACRO */

#define NB_TEXT 13
#define NB_BTN 10


typedef struct item{
    SDL_Texture *text[NB_TEXT], *text_on[NB_BTN], *text_target[NB_BTN];
    SDL_Rect positionText[NB_TEXT];
} item;

int* menu(SDL_Window *window, SDL_Renderer *renderer);
void loadingMenu(item *itemMenu, SDL_Renderer *renderer, SDL_Color *colors, int *ptSize);



#endif // MENU_H_INCLUDED
