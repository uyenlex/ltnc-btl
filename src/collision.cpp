#include "collision.h"

Collision::Collision(StupidSnake* stupidsnake, Apple* apple) {
    this->stupidsnake = stupidsnake;
    this->apple = apple;
}

bool Collision::toBorder() {
    bool over;
    //upper
    if (stupidsnake->head->headRect.y < 96) over = true; 
    else if (stupidsnake->head->headRect.y > SCREEN_HEIGHT) over = true;
    else if (stupidsnake->head->headRect.x < 0) over = true;
    else if (stupidsnake->head->headRect.x > SCREEN_WIDTH) over = true;
    else over = false;
    return over; 
}

void Collision::toApple() {
    if (SDL_HasIntersection(&stupidsnake->head->headRect, &apple->appleRect)) {
        stupidsnake->eatApple();
        switch(apple->chosenApple) {
            case 0: 
                score += 10;
                break;
            case 1:
                score += 15;
                break;
            case 2:
                score += 20;
                break;
            default:
                break;
        }
        apple->generate();
    }  
}

bool Collision::toItself() {
    for (int i = 1; i < stupidsnake->logic->segments.size(); i++) {
        if (SDL_HasIntersection(&stupidsnake->head->headRect, &stupidsnake->logic->segments[i].segmentRect))
            return true;
    }
    return false;
}