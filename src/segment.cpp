#include "segment.h"

Segment::Segment(SDL_Renderer* renderer, int x, int y) {
    this->renderer = renderer;
    segmentRect.x = x;
    segmentRect.y = y;
    segmentRect.w = RECT_SIZE;
    segmentRect.h = RECT_SIZE;
}

void Segment::segmentMove(int dir) {
    if (dir == UP) segmentRect.y -= RECT_SIZE;
    if (dir == DOWN) segmentRect.y += RECT_SIZE;
    if (dir == LEFT) segmentRect.x -= RECT_SIZE;
    if (dir == RIGHT) segmentRect.x += RECT_SIZE;
}

void Segment::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderFillRect(renderer, &segmentRect);
}