#ifndef GAME_SDL_C_INCLUDED
#define GAME_SDL_C_INCLUDED

#include <SDL.h>
//#include <SDL_Image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "../headers/ftc.h"
#include "../headers/ftc_SDL.h"
#include "../headers/game.h"

#define WHITE_COLOR {255,255,255,255}
#define DARK_CYAN_COLOR {24, 34, 44,255}
#define BLOODY_COLOR {173, 69, 70, 255}

#define FONTPATH_LETTER_ON "fonts\\friday13\\Friday13v12.ttf"
#define FONTPATH_LETTER_OFF "fonts\\friday13\\Friday13SH.ttf"

#define PT_SIZE_KEYBOARD 40
#define PT_SIZE_HIDDEN_WORD 70

void game_SDL(SDL_Window *window, SDL_Renderer *renderer, char *word, char *hiddenWord){
    /* Statements */
    int cursorOnKeyBoard = -1, ptSizeKeyboard = PT_SIZE_KEYBOARD, ptSizeHiddenWord = PT_SIZE_HIDDEN_WORD, wastedLetters[26] = {0}, life = 7,i;

    /* Struct Statements */
    letters keyboard[26];
    picture hangman, hiddenWordStruct;

    /* SDL Statements*/
    SDL_Color white = WHITE_COLOR, dark_cyan = DARK_CYAN_COLOR, bloody = BLOODY_COLOR;
    SDL_bool run = SDL_TRUE;
    SDL_Event event;

    load_keyboard(renderer, keyboard, ptSizeKeyboard, white, bloody);
    hangman = load_hangman(renderer, hangman);
    hiddenWordStruct = load_hidden_word(renderer, hiddenWord, bloody, ptSizeHiddenWord, hiddenWordStruct);

    /* Event handling */
    while(run){
        SDL_WaitEvent(&event);
        background(renderer, dark_cyan);
        show_texture(renderer, hangman.image, NULL , &hangman.imagePosition);
        show_keyboard(renderer, keyboard, wastedLetters);
        show_texture(renderer, hiddenWordStruct.image, NULL, &hiddenWordStruct.imagePosition);
        switch(event.type){

            /* Escape Window Event */
            case SDL_QUIT:
                run = SDL_FALSE;
                break;

            /* Mouse Motion Event */
            case SDL_MOUSEMOTION:
                /* Keyboard letter */
                for(i=0; i<26; i++){
                    if (event.motion.x > keyboard[i].positionText.x &&
                    event.motion.x < (keyboard[i].positionText.x + keyboard[i].positionText.w) &&
                    event.motion.y > keyboard[i].positionText.y &&
                    event.motion.y < (keyboard[i].positionText.y + keyboard[i].positionText.h)){
                        cursorOnKeyBoard = i;
                    }
                }
                if ((event.motion.x < keyboard[0].positionText.x || event.motion.x > (keyboard[12].positionText.x + keyboard[12].positionText.w)) ||
                    ((event.motion.y < keyboard[0].positionText.y || event.motion.y > (keyboard[0].positionText.y + keyboard[0].positionText.h)) &&
                    (event.motion.y < keyboard[25].positionText.y || event.motion.y > (keyboard[25].positionText.y + keyboard[25].positionText.h)))){
                        cursorOnKeyBoard = -1;
                    }
                break;

           /* Mouse click down Event */
            case SDL_MOUSEBUTTONDOWN:
                if( wastedLetters[cursorOnKeyBoard] == 0){
                    wastedLetters[cursorOnKeyBoard] = -1;
                    if (check_letter_and_reveal(word, &hiddenWord, cursorOnKeyBoard + 65)){
                        hiddenWordStruct = load_hidden_word(renderer, hiddenWord, bloody, ptSizeHiddenWord, hiddenWordStruct);
                        background(renderer, dark_cyan);
                        show_texture(renderer, hangman.image, NULL , &hangman.imagePosition);
                        show_keyboard(renderer, keyboard, wastedLetters);
                        show_texture(renderer, hiddenWordStruct.image, NULL, &hiddenWordStruct.imagePosition);
                    }
                    else
                        life--;
                }
                break;

            /* Keydown Event */
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    run = SDL_FALSE;
                break;
        }

        /* Selector Display */
        show_letterTarget(renderer, cursorOnKeyBoard, keyboard, wastedLetters);


        /* DEBUG */
        system("CLS");
        fprintf(stderr, "cursorOnKeyBoard %d\n", cursorOnKeyBoard);
        for(i=0; i<26; i++)
            fprintf(stderr, "wastedLetter %d : %d\n", i, wastedLetters[i]);
        fprintf(stderr, "life : %d\n", life);
        fprintf(stderr, "Word to find : %s\n", word);
        fprintf(stderr, "Hidden word : %s\n", hiddenWord);
        /* */

        SDL_RenderPresent(renderer);

        if (life == 0){
            fprintf(stderr, "********\n");
            fprintf(stderr, "Lose\n");
            fprintf(stderr, "********\n");
            SDL_Delay(3000);
            run = SDL_FALSE;
        }
        if(strcmpi(word,hiddenWord) == 0){
            fprintf(stderr, "********\n");
            fprintf(stderr, "Win\n");
            fprintf(stderr, "********\n");
            SDL_Delay(3000);
            run = SDL_FALSE;
        }
    }

    /* TOUTE LES TEXTURES ET SURFACES SONT A SUPPRIMER */
}


void load_keyboard(SDL_Renderer *renderer, letters *keyboard, int letterSize, SDL_Color colorPrimary, SDL_Color colorSecondary){
    int i;
    char alphabet = 'A'; /* Have a look at table ASCII to understand */
    for(i=0; i<26; i++){
        keyboard[i].text_on = text_texture(FONTPATH_LETTER_ON, letterSize, &alphabet, colorPrimary, renderer);
        keyboard[i].text_off = text_texture(FONTPATH_LETTER_OFF, letterSize, &alphabet, colorSecondary, renderer);
        keyboard[i].text_target = text_texture(FONTPATH_LETTER_ON, letterSize, &alphabet, colorSecondary, renderer);
        if (i<13){
            keyboard[i].positionText.x = i * 57 + 40;
            keyboard[i].positionText.y = 450;
        }else{
            keyboard[i].positionText.x = (i-12) * 57 - 20;
            keyboard[i].positionText.y = 525;
        }
        alphabet++;

    }
};

picture load_hidden_word(SDL_Renderer *renderer, char *hiddenWord, SDL_Color color, int ptSizeHiddenWord, picture hiddenWordStruct){
    hiddenWordStruct.imagePosition.x = 275;
    hiddenWordStruct.imagePosition.y = 350;
    hiddenWordStruct.image = text_texture(FONTPATH_LETTER_ON, ptSizeHiddenWord, hiddenWord, color, renderer);
    return hiddenWordStruct;
}

void show_keyboard(SDL_Renderer *renderer, letters *keyboard, int *wastedLetter){
    int i;
    for(i=0; i<26; i++){
        if(wastedLetter[i] == 0)
            show_texture(renderer, keyboard[i].text_on, NULL, &keyboard[i].positionText);
        else{
            SDL_DestroyTexture(keyboard[i].text_on);
            show_texture(renderer, keyboard[i].text_off, NULL, &keyboard[i].positionText);
        }
    }
}

picture load_hangman(SDL_Renderer *renderer, picture hangman){
    hangman.image = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("pictures\\hang_game.bmp"));
    hangman.imagePosition.x = 250;
    hangman.imagePosition.y = 10;
    if (hangman.image == NULL)
        fprintf(stderr, "Error SDL_CreateTextureFromSurface\n");
    return hangman;
}

void show_letterTarget(SDL_Renderer *renderer, int cursorOnKeyBoard, letters *keyboard, int *wastedLetters){
    int i;
    for(i=0; i<26; i++){
            if(i == cursorOnKeyBoard && wastedLetters[i] == 0)
                show_texture(renderer, keyboard[i].text_target, NULL, &keyboard[i].positionText);
    }
}
#endif // GAME_C_INCLUDED
