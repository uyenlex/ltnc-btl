#ifndef SEGMENT__H
#define SEGMENT__H

#include <SDL.h>
#include "const.h"

using namespace std;

class Segment {
public:
    Segment(SDL_Renderer* renderer, int x, int y);
    SDL_Rect segmentRect;
    void segmentMove(int dir);
    void draw();
private:
    SDL_Renderer* renderer;
};

#endif