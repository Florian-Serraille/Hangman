#ifndef FTC_SDL_H_INCLUDED
#define FTC_SDL_H_INCLUDED

void init_SDL(SDL_Window **window, SDL_Renderer **renderer);
void init(SDL_Window **window, SDL_Renderer **renderer, SDL_Texture *texture[], int nbTexture);
void quit_SDL(SDL_Window **window, SDL_Renderer **renderer);
void quit(SDL_Window **window, SDL_Renderer **renderer, SDL_Texture *texture[], int nbTexture);
void check_error(int returnValue);
void check_error_ttf(int returnValue);
void background(SDL_Renderer *renderer, SDL_Color color);
void draw_texture(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Color color);
void show_texture(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcRect, SDL_Rect *dstRect);
SDL_Texture* text_texture(char *fontPath, int ptSize, char *message, SDL_Color color, SDL_Renderer *renderer);

#endif // FTC_SDL_H_INCLUDED
