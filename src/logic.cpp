#include "logic.h"

Logic::Logic(SDL_Renderer* renderer, Head* head) {
    this->renderer = renderer;
    this->head = head;
    Segment newSegment(renderer, head->headRect.x - RECT_SIZE, head->headRect.y);
    segments.push_back(newSegment);
}

void Logic::append() {
    Segment newSegment(renderer, head->headRect.x, head->headRect.y);
    segments.insert(segments.begin(), newSegment); 
    //insert new segment before the beginning of the snake
}

void Logic::snakeUpdate() {
    rotate(segments.begin(), segments.begin()+1, segments.end());
    //move the latest segment to the end of the snake
    (segments.back()).segmentRect = head->headRect;
    //connect the last segment to the snake
}

void Logic::draw() {
    for (int i = 0; i < segments.size(); i++) {
        (segments[i]).draw();
    }
}