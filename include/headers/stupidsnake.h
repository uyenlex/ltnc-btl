#ifndef STUPIDSNAKE__H
#define STUPIDSNAKE__H

#include <SDL.h>
#include "head.h"
#include "logic.h"
#include "const.h"

using namespace std;

class StupidSnake {
public:
    StupidSnake(SDL_Renderer* renderer);
    Head* head;
    Logic* logic;
    void move(int dir);
    void eatApple();
    void update();
    void draw();

private:
    SDL_Renderer* renderer;
    int dir;
};

#endif
