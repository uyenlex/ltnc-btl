#ifndef MENU__H
#define MENU__H

#include <SDL.h>
#include <SDL_image.h>
#include "const.h"
#include "game.h"

class Menu {
public:
    Menu();
    bool checkIn(SDL_Rect check);
    bool MenuEventHandling();
    void draw();
private:
    Game *game;
    SDL_Rect startRect, insRect, escRect;
    SDL_Texture* menu;
    SDL_Texture* htp;
    SDL_Texture* paused;
    SDL_Renderer* renderer;
    int gameState;
    int delay;
};

#endif