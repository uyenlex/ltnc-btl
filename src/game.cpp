#include "game.h"

void Game::logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal) {
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

Game::Game() { //create window
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    if( TTF_Init() == -1 )
    {
        logSDLError(std::cout, "SDL_ttf_Init", true);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface* Icon = IMG_Load("res/img/icon.png");
	SDL_SetWindowIcon(window, Icon);

    font = TTF_OpenFont("res/fonts/amatic.ttf", 28);
    if (font == nullptr) cout << "unable to load font\n" << TTF_GetError() << "\n" ;

    SDL_Texture* _background = nullptr;
    SDL_Surface* loadedSurface = IMG_Load("res/img/bg.png");
    _background = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    this->background = _background;

    SDL_Texture* _gameover = nullptr;
    loadedSurface = IMG_Load("res/img/end.png");
    _gameover = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    this->gameover = _gameover;

    string s = "0";
    for (int i = 0; i < 10; i++) {
        s[0] = '0' + i;
        loadedSurface = TTF_RenderText_Solid(font, s.c_str(), {255,255,255});
        numbers[i] = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }

    alive = true;
    paused = false;
    snake = new StupidSnake(renderer);
    apple = new Apple(renderer, snake);
    hit = new Collision(snake, apple);
}

bool Game::notOver() {
    return alive;
}

void Game::keyPressed() {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                alive = false;
                break;
            case SDL_KEYDOWN: 
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                    case SDLK_w:
                        snake->move(UP);
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        snake->move(DOWN);
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        snake->move(LEFT);
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        snake->move(RIGHT);
                        break;
                    case SDLK_p:
                        paused = 1 - paused;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void Game::algorithm() {
    if (hit->toBorder() or hit->toItself()) alive = false;
    hit->toApple();
}

void Game::update() {
    if (!paused) snake->update();
}

void Game::renderGame() {
    SDL_RenderCopy(renderer, background, NULL, NULL);
    drawScore();
    snake->draw();
    apple->draw();
    // SDL_RenderPresent(renderer);
}

void Game::close() {
    cout << "Your score is: " << hit->score << endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
}

void Game::gameOver() {
    SDL_RenderCopy(renderer, gameover, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

bool Game::isPaused() {
    return paused;
}

void Game::drawScore() {
    vector<int> v;
    int x = hit->score;
    if (x == 0) v.push_back(0);
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }

    SDL_Rect fillRect = {278, 15, 40, 70};
    for (int i = v.size()-1; i >= 0; i--) {
        SDL_RenderCopy(renderer, numbers[v[i]], NULL, &fillRect);
        fillRect.x += fillRect.w;
    }
}