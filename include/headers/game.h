#ifndef GAME__H
#define GAME__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "stupidsnake.h"
#include "apple.h"
#include "collision.h"
#include "const.h"

using namespace std;

class Game {
public:
    Game();
    void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);
    bool notOver();
    void keyPressed();
    void algorithm();
    void update();
    void renderGame();
    void close();
    void gameOver();
    SDL_Renderer* getRenderer();
    bool isPaused();
    void drawScore();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* background;
    SDL_Texture* gameover;

    bool alive, paused;
    StupidSnake* snake;
    Apple* apple;
    Collision* hit;

    TTF_Font* font;
    SDL_Texture *numbers[10];
    vector<int> v;

    const string WINDOW_TITLE = "Dumb Snake";
};

#endif