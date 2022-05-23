#ifndef COLLISION__H
#define COLLISION_H

#include <SDL.h>
#include "stupidsnake.h"
#include "apple.h"
#include "const.h"

using namespace std;

class Collision{
public:
    Collision(StupidSnake* stupidsnake, Apple* apple);
    bool toBorder();
    void toApple();
    bool toItself();
    int score = 0;
private:
    StupidSnake* stupidsnake;
    Apple* apple;
};

#endif