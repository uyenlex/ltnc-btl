#ifndef APPLE__H
#define APPLE__H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "stupidsnake.h"
#include "segment.h"
#include "const.h"

using namespace std;

class Apple {
public:
    Apple(SDL_Renderer* renderer, StupidSnake* stupidsnake);
    SDL_Rect appleRect;
    void generate();
    void draw();
    int chosenApple;
private:
    SDL_Renderer* renderer;
    StupidSnake* snake;
    SDL_Texture* apple = nullptr;
    SDL_Texture* cheese = nullptr;
    SDL_Texture* heart = nullptr;
};

#endif