#include "stupidsnake.h"

StupidSnake::StupidSnake(SDL_Renderer* renderer) {
    this->renderer = renderer;
    dir = 0;
    head = new Head(renderer);
    logic = new Logic(renderer, head);
}

void StupidSnake::move(int dir) {
    if (dir == UP and this->dir != DOWN) this->dir = UP;
    else if (dir == DOWN and this->dir != UP) this->dir = DOWN;
    else if (dir == LEFT and this->dir != RIGHT) this->dir = LEFT;
    else if (dir == RIGHT and this->dir != LEFT) this->dir = RIGHT;
}

void StupidSnake::eatApple() {
    logic->append();
}

void StupidSnake::update() {
    logic->snakeUpdate();
    head->headMove(dir);
}

void StupidSnake::draw() {
    head->draw();
    logic->draw();
}