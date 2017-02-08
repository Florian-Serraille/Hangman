#ifndef GAME_H_INCLUDED
#define INTRO_H_INCLUDED

typedef struct letters{
    SDL_Texture *text_on, *text_off, *text_target;
    SDL_Rect positionText;
} letters;

typedef struct picture{
    SDL_Texture *image;
    SDL_Rect imagePosition;
} picture;

void game_SDL(SDL_Window *window, SDL_Renderer *renderer, char *word, char *hiddenWord);
void load_keyboard(SDL_Renderer *renderer, letters *keybord, int letterSize, SDL_Color colorPrimary, SDL_Color colorSeconday);
picture load_hidden_word(SDL_Renderer *renderer, char *hiddenWord, SDL_Color color, int ptSizeHiddenWord, picture hiddenWordStruct);
void show_keyboard(SDL_Renderer *renderer, letters *keyboard, int *wastedLetter);
picture load_hangman(SDL_Renderer *renderer, picture hangman);
void show_letterTarget(SDL_Renderer *renderer, int cursorOnKeyBoard, letters *keyboard, int *wastedLetters);

#endif // GAME_H_INCLUDED
