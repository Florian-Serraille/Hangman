#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED

#include <SDL.h>
//#include <SDL_Image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "../headers/ftc.h"
#include "../headers/ftc_SDL.h"
#include "../headers/menu.h"

/* MACRO TEXTURE */

#define NB_TEXT 13
#define NB_BTN 10
#define PLAY 0
#define LANG_1 1
#define LANG_2 2
#define LANG_3 3
#define THEME_ALL 4
#define THEME_1 5
#define THEME_2 6
#define THEME_3 7
#define THEME_4 8
#define THEME_5 9
#define THEME 10
#define LANG 11
#define TITLE 12

#define PLAY_TEXT "JOGAR"
#define LANG_TEXT_1 "PORTUGUES"
#define LANG_TEXT_2 "INGLES"
#define LANG_TEXT_3 "FRANCES"
#define THEME_TEXT_ALL "TODOS"
#define THEME_TEXT_1 "ANIMAIS"
#define THEME_TEXT_2 "GEOGRAFIA"
#define THEME_TEXT_3 "ARMAS"
#define THEME_TEXT_4 "ESPORTE"
#define THEME_TEXT_5 "HISTORIA"
#define THEME_TEXT "TEMATICA :"
#define LANG_TEXT "LINGUA :"
#define TITLE_TEXT "HANGMAN"


/* MACRO COLOR */
#define NB_COLORS 5
#define RED_COLOR {255,0,0,255}
#define BLUE_COLOR {0,0,255,255}
#define WHITE_COLOR {255,255,255,255}
#define DARK_CYAN_COLOR {24, 34, 44,255}
#define BLOODY_COLOR {173, 69, 70, 255}
#define RED 0
#define BLUE 1
#define WHITE 2
#define DARK_CYAN 3
#define BLOODY 4

/* MACRO TTF */
#define FONTPATH_MENU "fonts\\friday13\\Friday13v12.ttf"
#define PTSIZE_BODY_MENU 30
#define PTSIZE_TITLE_MENU 60
#define PTSIZE_BODY 0
#define PTSIZE_TITLE 1

/* MACRO SETTINGS & CURSOR */
#define DEFAULT_SETTINGS {4,1} // ALL, PORTUGUES
#define XPOS_CURSOR 0
#define YPOS_CURSOR 1
#define THEME_SETTING 0
#define LANG_SETTING 1


int* menu(SDL_Window *window, SDL_Renderer *renderer){

    /* Statement*/
    int cursor[2];
    int settings[2] = DEFAULT_SETTINGS;
    int ptSize[2] = {PTSIZE_BODY_MENU, PTSIZE_TITLE_MENU};

    /* Statements SDL */
    item itemMenu;
    SDL_bool run = SDL_TRUE;
    SDL_Event event;
    SDL_Color colors[NB_COLORS] = {RED_COLOR, BLUE_COLOR, WHITE_COLOR, DARK_CYAN_COLOR, BLOODY_COLOR};

    loadingMenu(&itemMenu, renderer, colors, ptSize);

    /* Set x/y cursor position in the window */
    SDL_WarpMouseInWindow(window, 400, 530);

    /* Event handling */
    while(run){
        SDL_WaitEvent(&event);
        switch(event.type){

            /* Escape Window Event */
            case SDL_QUIT:
                run = SDL_FALSE;
                break;

            /* Mouse Motion Event */
            case SDL_MOUSEMOTION:
                /* PLAY Button */
                if (event.motion.x > itemMenu.positionText[PLAY].x &&
                    event.motion.x < (itemMenu.positionText[PLAY].x + itemMenu.positionText[PLAY].w) &&
                    event.motion.y > itemMenu.positionText[PLAY].y &&
                    event.motion.y < (itemMenu.positionText[PLAY].y + itemMenu.positionText[PLAY].h)){
                    cursor[XPOS_CURSOR] = 0;
                    cursor[YPOS_CURSOR] = 3;
                }else{
                    /* LANG_1 Button */
                    if (event.motion.x > itemMenu.positionText[LANG_1].x &&
                        event.motion.x < (itemMenu.positionText[LANG_1].x + itemMenu.positionText[LANG_1].w) &&
                        event.motion.y > itemMenu.positionText[LANG_1].y &&
                        event.motion.y < (itemMenu.positionText[LANG_1].y + itemMenu.positionText[LANG_1].h)){
                        cursor[XPOS_CURSOR] = 0;
                        cursor[YPOS_CURSOR] = 2;
                    }else{
                        /* LANG_2 Button */
                        if (event.motion.x > itemMenu.positionText[LANG_2].x &&
                            event.motion.x < (itemMenu.positionText[LANG_2].x + itemMenu.positionText[LANG_2].w) &&
                            event.motion.y > itemMenu.positionText[LANG_2].y &&
                            event.motion.y < (itemMenu.positionText[LANG_2].y + itemMenu.positionText[LANG_2].h)){
                            cursor[XPOS_CURSOR] = 1;
                            cursor[YPOS_CURSOR] = 2;
                        }else{
                            /* LANG_3 Button */
                            if (event.motion.x > itemMenu.positionText[LANG_3].x &&
                                event.motion.x < (itemMenu.positionText[LANG_3].x + itemMenu.positionText[LANG_3].w) &&
                                event.motion.y > itemMenu.positionText[LANG_3].y &&
                                event.motion.y < (itemMenu.positionText[LANG_3].y + itemMenu.positionText[LANG_3].h)){
                                cursor[XPOS_CURSOR] = 2;
                                cursor[YPOS_CURSOR] = 2;
                            }else{
                                /* THEME_ALL Button */
                                if (event.motion.x > itemMenu.positionText[THEME_ALL].x &&
                                    event.motion.x < (itemMenu.positionText[THEME_ALL].x + itemMenu.positionText[THEME_ALL].w) &&
                                    event.motion.y > itemMenu.positionText[THEME_ALL].y &&
                                    event.motion.y < (itemMenu.positionText[THEME_ALL].y + itemMenu.positionText[THEME_ALL].h)){
                                    cursor[XPOS_CURSOR] = 0;
                                    cursor[YPOS_CURSOR] = 0;
                                }else{
                                    /* THEME_1 Button */
                                    if (event.motion.x > itemMenu.positionText[THEME_1].x &&
                                        event.motion.x < (itemMenu.positionText[THEME_1].x + itemMenu.positionText[THEME_1].w) &&
                                        event.motion.y > itemMenu.positionText[THEME_1].y &&
                                        event.motion.y < (itemMenu.positionText[THEME_1].y + itemMenu.positionText[THEME_1].h)){
                                        cursor[XPOS_CURSOR] = 1;
                                        cursor[YPOS_CURSOR] = 0;
                                    }else{
                                        /* THEME_2 Button */
                                        if (event.motion.x > itemMenu.positionText[THEME_2].x &&
                                            event.motion.x < (itemMenu.positionText[THEME_2].x + itemMenu.positionText[THEME_2].w) &&
                                            event.motion.y > itemMenu.positionText[THEME_2].y &&
                                            event.motion.y < (itemMenu.positionText[THEME_2].y + itemMenu.positionText[THEME_2].h)){
                                            cursor[XPOS_CURSOR] = 2;
                                            cursor[YPOS_CURSOR] = 0;
                                        }else{
                                             /* THEME_3 Button */
                                            if (event.motion.x > itemMenu.positionText[THEME_3].x &&
                                                event.motion.x < (itemMenu.positionText[THEME_3].x + itemMenu.positionText[THEME_3].w) &&
                                                event.motion.y > itemMenu.positionText[THEME_3].y &&
                                                event.motion.y < (itemMenu.positionText[THEME_3].y + itemMenu.positionText[THEME_3].h)){
                                                cursor[XPOS_CURSOR] = 0;
                                                cursor[YPOS_CURSOR] = 1;
                                            }else{
                                                /* THEME_4 Button */
                                                if (event.motion.x > itemMenu.positionText[THEME_4].x &&
                                                    event.motion.x < (itemMenu.positionText[THEME_4].x + itemMenu.positionText[THEME_4].w) &&
                                                    event.motion.y > itemMenu.positionText[THEME_4].y &&
                                                    event.motion.y < (itemMenu.positionText[THEME_4].y + itemMenu.positionText[THEME_4].h)){
                                                    cursor[XPOS_CURSOR] = 1;
                                                    cursor[YPOS_CURSOR] = 1;
                                                }else{
                                                    /* THEME_5 Button */
                                                    if (event.motion.x > itemMenu.positionText[THEME_5].x &&
                                                        event.motion.x < (itemMenu.positionText[THEME_5].x + itemMenu.positionText[THEME_5].w) &&
                                                        event.motion.y > itemMenu.positionText[THEME_5].y &&
                                                        event.motion.y < (itemMenu.positionText[THEME_5].y + itemMenu.positionText[THEME_5].h)){
                                                        cursor[XPOS_CURSOR] = 2;
                                                        cursor[YPOS_CURSOR] = 1;
                                                    }else{
                                                        cursor[XPOS_CURSOR] = -1;
                                                        cursor[YPOS_CURSOR] = -1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;

            /* Mouse click down Event */

            case SDL_MOUSEBUTTONDOWN:
                if(cursor[XPOS_CURSOR] == 0 && cursor[YPOS_CURSOR] == 0)
                    settings[THEME_SETTING] = THEME_ALL;
                else
                    if(cursor[XPOS_CURSOR] == 1 && cursor[YPOS_CURSOR] == 0)
                        settings[THEME_SETTING] = THEME_1;
                    else
                        if(cursor[XPOS_CURSOR] == 2 && cursor[YPOS_CURSOR] == 0)
                        settings[THEME_SETTING] = THEME_2;
                        else
                            if(cursor[XPOS_CURSOR] == 0 && cursor[YPOS_CURSOR] == 1)
                                settings[THEME_SETTING] = THEME_3;
                            else
                                if(cursor[XPOS_CURSOR] == 1 && cursor[YPOS_CURSOR] == 1)
                                    settings[THEME_SETTING] = THEME_4;
                                else
                                    if(cursor[XPOS_CURSOR] == 2 && cursor[YPOS_CURSOR] == 1)
                                        settings[THEME_SETTING] = THEME_5;
                                    else
                                        if(cursor[XPOS_CURSOR] == 0 && cursor[YPOS_CURSOR] == 2)
                                            settings[LANG_SETTING] = LANG_1;
                                        else
                                            if(cursor[XPOS_CURSOR] == 1 && cursor[YPOS_CURSOR] == 2)
                                                settings[LANG_SETTING] = LANG_2;
                                            else
                                                if(cursor[XPOS_CURSOR] == 2 && cursor[YPOS_CURSOR] == 2)
                                                    settings[LANG_SETTING] = LANG_3;
                                                else
                                                    if(cursor[XPOS_CURSOR] == 0 && cursor[YPOS_CURSOR] == 3)
                                                        return settings;
                break;

                /* Keydown Event */

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    run = SDL_FALSE;
                if(event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_RETURN)
                    return settings;
                break;
            }

    /* Display menu */

    background(renderer, colors[DARK_CYAN]);
    show_texture(renderer, itemMenu.text_on[PLAY], NULL, &itemMenu.positionText[PLAY]);
    show_texture(renderer, itemMenu.text[LANG], NULL, &itemMenu.positionText[LANG]);
    show_texture(renderer, itemMenu.text[LANG_1], NULL, &itemMenu.positionText[LANG_1]);
    show_texture(renderer, itemMenu.text[LANG_2], NULL, &itemMenu.positionText[LANG_2]);
    show_texture(renderer, itemMenu.text[LANG_3], NULL, &itemMenu.positionText[LANG_3]);
    show_texture(renderer, itemMenu.text[THEME], NULL, &itemMenu.positionText[THEME]);
    show_texture(renderer, itemMenu.text[THEME_ALL], NULL, &itemMenu.positionText[THEME_ALL]);
    show_texture(renderer, itemMenu.text[THEME_1], NULL, &itemMenu.positionText[THEME_1]);
    show_texture(renderer, itemMenu.text[THEME_2], NULL, &itemMenu.positionText[THEME_2]);
    show_texture(renderer, itemMenu.text[THEME_3], NULL, &itemMenu.positionText[THEME_3]);
    show_texture(renderer, itemMenu.text[THEME_4], NULL, &itemMenu.positionText[THEME_4]);
    show_texture(renderer, itemMenu.text[THEME_5], NULL, &itemMenu.positionText[THEME_5]);
    show_texture(renderer, itemMenu.text[TITLE], NULL, &itemMenu.positionText[TITLE]);

    /* Selector Display */

    /* THEME */
    /* THEME_ALL */
    if(settings[THEME_SETTING] == THEME_ALL)
        show_texture(renderer, itemMenu.text_on[THEME_ALL], NULL, &itemMenu.positionText[THEME_ALL]);
    /* THEME_1 */
    if(settings[THEME_SETTING] == THEME_1)
        show_texture(renderer, itemMenu.text_on[THEME_1], NULL, &itemMenu.positionText[THEME_1]);
    /* THEME_2 */
    if(settings[THEME_SETTING] == THEME_2)
        show_texture(renderer, itemMenu.text_on[THEME_2], NULL, &itemMenu.positionText[THEME_2]);
    /* THEME_3 */
    if(settings[THEME_SETTING] == THEME_3)
        show_texture(renderer, itemMenu.text_on[THEME_3], NULL, &itemMenu.positionText[THEME_3]);
    /* THEME_4 */
    if(settings[THEME_SETTING] == THEME_4)
        show_texture(renderer, itemMenu.text_on[THEME_4], NULL, &itemMenu.positionText[THEME_4]);
    /* THEME_5 */
    if(settings[THEME_SETTING] == THEME_5)
        show_texture(renderer, itemMenu.text_on[THEME_5], NULL, &itemMenu.positionText[THEME_5]);
    /* LANG */
    /* LANG_1 */
    if(settings[LANG_SETTING] == LANG_1)
        show_texture(renderer, itemMenu.text_on[LANG_1], NULL, &itemMenu.positionText[LANG_1]);
    /* LANG_2 */
    if(settings[LANG_SETTING] == LANG_2)
        show_texture(renderer, itemMenu.text_on[LANG_2], NULL, &itemMenu.positionText[LANG_2]);
    /* LANG_3 */
    if(settings[LANG_SETTING] == LANG_3)
        show_texture(renderer, itemMenu.text_on[LANG_3], NULL, &itemMenu.positionText[LANG_3]);

    /* Cursor Display */

    check_error(SDL_SetRenderDrawColor(renderer, colors[BLOODY].r, colors[BLOODY].g ,colors[BLOODY].b, colors[BLOODY].a));
    /* PLAY */
    if(cursor[XPOS_CURSOR] == 0 &&  cursor[YPOS_CURSOR] == 3)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[PLAY]);
    /* LANG_1 */
    if(cursor[XPOS_CURSOR] == 0 &&  cursor[YPOS_CURSOR] == 2)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[LANG_1]);
    /* LANG_2 */
    if(cursor[XPOS_CURSOR] == 1 &&  cursor[YPOS_CURSOR] == 2)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[LANG_2]);
    /* LANG_3 */
    if(cursor[XPOS_CURSOR] == 2 &&  cursor[YPOS_CURSOR] == 2)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[LANG_3]);
    /* THEME_ALL */
    if(cursor[XPOS_CURSOR] == 0 &&  cursor[YPOS_CURSOR] == 0)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_ALL]);
    /* THEME_1 */
    if(cursor[XPOS_CURSOR] == 1 &&  cursor[YPOS_CURSOR] == 0)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_1]);
    /* THEME_2 */
    if(cursor[XPOS_CURSOR] == 2 &&  cursor[YPOS_CURSOR] == 0)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_2]);
    /* THEME_3 */
    if(cursor[XPOS_CURSOR] == 0 &&  cursor[YPOS_CURSOR] == 1)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_3]);
    /* THEME_4 */
    if(cursor[XPOS_CURSOR] == 1 &&  cursor[YPOS_CURSOR] == 1)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_4]);
    /* THEME_5 */
    if(cursor[XPOS_CURSOR] == 2 &&  cursor[YPOS_CURSOR] == 1)
        SDL_RenderDrawRect(renderer, &itemMenu.positionText[THEME_5]);

    SDL_RenderPresent(renderer);
    }

    return settings;
}

void loadingMenu(item *itemMenu, SDL_Renderer *renderer, SDL_Color *colors, int *ptSize){
    int i;
    for(i=0; i<NB_TEXT; i++){
        switch(i){
            case PLAY:
                itemMenu->text[PLAY] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY] , PLAY_TEXT, colors[WHITE], renderer);
                itemMenu->text_on[PLAY] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], PLAY_TEXT, colors[BLOODY], renderer);
                itemMenu->text_target[PLAY] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], PLAY_TEXT, colors[BLUE], renderer);
                itemMenu->positionText[PLAY].x = 350;
                itemMenu->positionText[PLAY].y = 520;
                break;
            case LANG:
                itemMenu->text[LANG] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT, colors[WHITE], renderer);
                itemMenu->positionText[LANG].x = 100;
                itemMenu->positionText[LANG].y = 400;
            case LANG_1:
                itemMenu->text[LANG_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_1, colors[WHITE], renderer);
                itemMenu->text_on[LANG_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_1, colors[BLOODY], renderer);
                itemMenu->text_target[LANG_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_1, colors[BLUE], renderer);
                itemMenu->positionText[LANG_1].x = 250;
                itemMenu->positionText[LANG_1].y = 400;
            case LANG_2:
                itemMenu->text[LANG_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_2, colors[WHITE], renderer);
                itemMenu->text_on[LANG_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_2, colors[BLOODY], renderer);
                itemMenu->text_target[LANG_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_2, colors[BLUE], renderer);
                itemMenu->positionText[LANG_2].x = 450;
                itemMenu->positionText[LANG_2].y = 400;
                break;
            case LANG_3:
                itemMenu->text[LANG_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_3, colors[WHITE], renderer);
                itemMenu->text_on[LANG_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_3, colors[BLOODY], renderer);
                itemMenu->text_target[LANG_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], LANG_TEXT_3, colors[BLUE], renderer);
                itemMenu->positionText[LANG_3].x = 600;
                itemMenu->positionText[LANG_3].y = 400;
                break;
            case THEME:
                itemMenu->text[THEME] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT, colors[WHITE], renderer);
                itemMenu->positionText[THEME].x = 100;
                itemMenu->positionText[THEME].y = 200;
                break;
            case THEME_ALL:
                itemMenu->text[THEME_ALL] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_ALL, colors[WHITE], renderer);
                itemMenu->text_on[THEME_ALL] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_ALL, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_ALL] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_ALL, colors[BLUE], renderer);
                itemMenu->positionText[THEME_ALL].x = 250;
                itemMenu->positionText[THEME_ALL].y = 200;
                break;
            case THEME_1:
                itemMenu->text[THEME_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_1, colors[WHITE], renderer);
                itemMenu->text_on[THEME_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_1, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_1] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_1, colors[BLUE], renderer);
                itemMenu->positionText[THEME_1].x = 400;
                itemMenu->positionText[THEME_1].y = 200;
                break;
            case THEME_2:
                itemMenu->text[THEME_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_2, colors[WHITE], renderer);
                itemMenu->text_on[THEME_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_2, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_2] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_2, colors[BLUE], renderer);
                itemMenu->positionText[THEME_2].x = 550;
                itemMenu->positionText[THEME_2].y = 200;
                break;
            case THEME_3:
                itemMenu->text[THEME_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_3, colors[WHITE], renderer);
                itemMenu->text_on[THEME_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_3, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_3] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_3, colors[BLUE], renderer);
                itemMenu->positionText[THEME_3].x = 250;
                itemMenu->positionText[THEME_3].y = 300;
            case THEME_4:
                itemMenu->text[THEME_4] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_4, colors[WHITE], renderer);
                itemMenu->text_on[THEME_4] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_4, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_4] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_4, colors[BLUE], renderer);
                itemMenu->positionText[THEME_4].x = 400;
                itemMenu->positionText[THEME_4].y = 300;
                break;
            case THEME_5:
                itemMenu->text[THEME_5] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_5, colors[WHITE], renderer);
                itemMenu->text_on[THEME_5] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_5, colors[BLOODY], renderer);
                itemMenu->text_target[THEME_5] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_BODY], THEME_TEXT_5, colors[BLUE], renderer);
                itemMenu->positionText[THEME_5].x = 550;
                itemMenu->positionText[THEME_5].y = 300;
                break;
            case TITLE:
                itemMenu->text[TITLE] = text_texture(FONTPATH_MENU, ptSize[PTSIZE_TITLE], TITLE_TEXT, colors[BLOODY], renderer);
                itemMenu->positionText[TITLE].x = 300;
                itemMenu->positionText[TITLE].y = 50;
                break;
        }
    }
}


#endif // MENU_C_INCLUDED
