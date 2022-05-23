#include "head.h"

Head::Head(SDL_Renderer* renderer) {
    this->renderer = renderer;
    headRect.x = 0;
    headRect.y = 96;
    headRect.w = RECT_SIZE;
    headRect.h = RECT_SIZE;
}

void Head::headMove(int dir) {
    if (dir == UP) headRect.y -= RECT_SIZE;
    if (dir == DOWN) headRect.y += RECT_SIZE;
    if (dir == LEFT) headRect.x -= RECT_SIZE;
    if (dir == RIGHT) headRect.x += RECT_SIZE;
}

void Head::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &headRect);
}