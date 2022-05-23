#ifndef HEAD__H
#define HEAD__H

#include <SDL.h>
#include <iostream>
#include "const.h"

using namespace std;

class Head {
public:
    Head(SDL_Renderer* renderer);
    SDL_Rect headRect;
    void headMove(int dir);
    void draw();
private:
    SDL_Renderer* renderer;
};

#endif