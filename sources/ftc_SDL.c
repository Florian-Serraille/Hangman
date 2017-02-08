#ifndef FONCTION_C_SDL_INCLUDED
#define FONCTION_C_SDL_INCLUDED

#include <SDL.h>
//#include <SDL_Image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "../headers/ftc_SDL.h"


/* Macro SDL */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


void init_SDL(SDL_Window **window, SDL_Renderer **renderer){
    check_error(SDL_Init(SDL_INIT_EVERYTHING));
    check_error_ttf(TTF_Init());
    if((*window = SDL_CreateWindow("Hangman",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    WINDOW_WIDTH,
                                    WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN)) == NULL){
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    }
    if((*renderer = SDL_CreateRenderer(*window,
                                        -1,
                                        SDL_RENDERER_ACCELERATED)) == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
    }
}


void quit_SDL(SDL_Window **window, SDL_Renderer **renderer){
     if(NULL != *renderer)
        SDL_DestroyRenderer(*renderer);
    if(NULL != *window)
        SDL_DestroyWindow(*window);
    TTF_Quit();
    SDL_Quit();
}

/* check_error */
/* check any error (!0) in the function return value */

void check_error (int returnValue){
    if (returnValue != 0){
        fprintf(stderr, "SDL error : %s\n", SDL_GetError());
        SDL_Delay(2000);
        exit(EXIT_FAILURE);
    }
}

/* background */
/* change the background color */

void background(SDL_Renderer *renderer, SDL_Color color){
    check_error(SDL_SetRenderDrawColor(renderer, color.r, color.g ,color.b, color.a));
    check_error(SDL_RenderClear(renderer));
}

/* draw_texture */
/* draw color on one texture */

void draw_texture(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Color color){
    check_error(SDL_SetRenderTarget(renderer, texture));
    check_error(SDL_SetRenderDrawColor(renderer, color.r, color.g ,color.b, color.a));
    check_error(SDL_RenderClear(renderer));
    check_error(SDL_SetRenderTarget(renderer, NULL));
}

/* show_texture */
/* copy one texture on the renderer */

void show_texture(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcRect, SDL_Rect *dstRect){
    if(srcRect == NULL && dstRect == NULL)
        check_error(SDL_RenderCopy(renderer, texture, NULL, NULL));
    else{
        if(srcRect == NULL){
            check_error(SDL_QueryTexture(texture, NULL,NULL,&dstRect->w,&dstRect->h));
            check_error(SDL_RenderCopy(renderer, texture, NULL, dstRect));
        }
        if(dstRect == NULL){
            check_error(SDL_QueryTexture(texture, NULL,NULL,&dstRect->w,&dstRect->h));
            check_error(SDL_RenderCopy(renderer, texture, srcRect, NULL));
        }
    }
    if(srcRect != NULL && dstRect != NULL){
            check_error(SDL_QueryTexture(texture, NULL,NULL,&dstRect->w,&dstRect->h));
            check_error(SDL_RenderCopy(renderer, texture, srcRect, dstRect));
    }
}

/* check_error_ttf */
/* check any error (!0) in a ttf function return value */

void check_error_ttf(int returnValue){
    if (returnValue != 0){
        fprintf(stderr, "TTF error : %s\n", TTF_GetError());
        SDL_Delay(2000);
        exit(EXIT_FAILURE);
    }
}

/* texte_texture */
/* open the font, put it on a surface and convert it to a texture wich is returned and free/close surface and font */

SDL_Texture* text_texture(char *fontPath, int ptSize, char *message, SDL_Color color, SDL_Renderer *renderer){
	TTF_Font *font;
	SDL_Surface *tmpSurface;
	SDL_Texture *tmpTexture;
	if ((font = TTF_OpenFont(fontPath, ptSize)) == NULL){
        fprintf(stderr, "Error : %s\n", TTF_GetError());
	}

	if ((tmpSurface = TTF_RenderText_Blended(font, message, color)) == NULL){
        fprintf(stderr, "Error : %s\n", TTF_GetError());
	}
	if ((tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface)) == NULL){
        fprintf(stderr, "Error : %s\n", SDL_GetError());
	}
	TTF_CloseFont(font);
	SDL_FreeSurface(tmpSurface);
	return tmpTexture;
}


#endif // FONCTION_C_SDL_INCLUDED
