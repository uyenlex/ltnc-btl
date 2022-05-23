#include "apple.h"

Apple::Apple(SDL_Renderer* renderer, StupidSnake* stupidsnake) {
    this->renderer = renderer;
    this->snake = stupidsnake;
    SDL_Texture* _apple = nullptr;
    SDL_Texture* _cheese = nullptr;
    SDL_Texture* _heart = nullptr;

    SDL_Surface* loadedSurface = IMG_Load("res/img/apple.png");
    _apple = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    this->apple = _apple;

    loadedSurface = IMG_Load("res/img/cheese.png");
    _cheese = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    this->cheese = _cheese;

    loadedSurface = IMG_Load("res/img/heart.png");
    _heart = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    this->heart = _heart;

    generate();
}

void Apple::generate() {
    bool valid = true;
    int dx, dy;
    chosenApple = rand() % 3;
    while (valid) {
        dx = rand() % (SCREEN_WIDTH - RECT_SIZE);
        dy = rand() % (SCREEN_HEIGHT - RECT_SIZE);
        if (dy <= 96) dy += 96;
        if (dx % RECT_SIZE == 0 and dy % RECT_SIZE == 0)
            valid = false;
    }
    // cout << dx << " " << dy << endl;
    appleRect.x = dx;
    appleRect.y = dy;
    appleRect.h = RECT_SIZE;
    appleRect.w = RECT_SIZE;
}

void Apple::draw() {
    switch (chosenApple) {
        case 0: 
            SDL_RenderCopy(renderer, apple, NULL, &appleRect);
            // SDL_RenderPresent(renderer);
            break;
        case 1: 
            SDL_RenderCopy(renderer, cheese, NULL, &appleRect);
            // SDL_RenderPresent(renderer);
            break;
        case 2: 
            SDL_RenderCopy(renderer, heart, NULL, &appleRect);
            // SDL_RenderPresent(renderer);
            break;
    }
}