#include "menu.h"

Menu::Menu() {
    game = new Game;
    renderer = game->getRenderer();
    delay = 0;
    gameState = 1;
    
    startRect.x = 470;
    startRect.y = 252;
    startRect.w = 318;
    startRect.h = 82;

    insRect.x = 471;
    insRect.y = 386;
    insRect.w = 322;
    insRect.h = 75;

    escRect.x = 9;
    escRect.y = 9;
    escRect.w = 76;
    escRect.h = 48;

    SDL_Surface* loadedSurface = IMG_Load("res/img/menu.png");
    menu = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    if (menu == nullptr) cout << "unsuccessfully load menu\n" ;

    loadedSurface = IMG_Load("res/img/howtoplay.png");
    htp = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    loadedSurface = IMG_Load("res/img/paused.png");
    paused = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
}

bool Menu::checkIn(SDL_Rect check) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (check.x <= x and x <= check.x+check.w and check.y <= y and y <= check.y+check.h) 
        return true;
    return false;
}

bool Menu::MenuEventHandling() {
    bool quit = false;
    SDL_Event e;
    switch (gameState) {
        case 0: // in game
            if (game->notOver()) {
                game->keyPressed();
                game->algorithm();
                if (delay == 10) {
                    game->update();
                    delay = 0;
                }
                // SDL_Delay(10);
                delay++;
            } else {
                game->gameOver();
                game->close();
                quit = true;
            }
            break;
        case 1: // menu
            if (SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT:
                        // game->gameOver();
                        game->close();
                        quit = true;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (checkIn(startRect)) {
                            // game = new Game;
                            // renderer = game->getRenderer();
                            gameState = 0;
                        }
                        if (checkIn(insRect)) {
                            gameState = 2;
                        }
                        break;
                }
            }
            break;
        case 2: // how to play
            if (SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT:
                        // game->gameOver();
                        game->close();
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        if (e.key.keysym.sym == SDLK_ESCAPE) {
                            gameState = 1;
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (checkIn(escRect)) { // back to menu screen
                            gameState = 1;
                        }
                        break;
                }
            }
            break;
        default:
            // game->gameOver();
            game->close();
            quit = true;
            break;
        }
    return quit;
}

void Menu::draw() {
    switch (gameState) {
        case 0:
            game->renderGame();
            if (game->isPaused()) {
                // cout << "game paused\n" ;
                SDL_RenderCopy(renderer, paused, NULL, NULL);
            }
            break;
        case 1: // ve menu
            SDL_RenderCopy(renderer, menu, NULL, NULL);
            break;
        case 2:
            SDL_RenderCopy(renderer, htp, NULL, NULL);
            break;
        default:
            break;
    }
    SDL_RenderPresent(renderer);
}