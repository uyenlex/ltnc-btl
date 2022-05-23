#ifndef LOGIC__H
#define LOGIC__H

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include "head.h"
#include "segment.h"
#include "const.h"

using namespace std;

class Logic {
public:
    Logic(SDL_Renderer* renderer, Head* head);
    vector<Segment> segments;

    void append();
    void snakeUpdate();
    void draw();
private:
    SDL_Renderer* renderer;
    Head* head;
};

#endif