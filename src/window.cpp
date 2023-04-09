#include "window.hpp"
#include <ctime>

Window::Window() {
    if(!init("time shifter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, 0))
        return;
    if(!load())
        return;
}

Window::~Window(){
    quit();
}

bool Window::init(const char *title, int x, int y, int w, int h, Uint32 flags) {
    win = SDL_CreateWindow(title, x, y, w, h, flags);
    if(win == nullptr) return false;

    ren = SDL_CreateRenderer(win, -1, 0);
    if(ren == nullptr) return false;
    return true;
}

bool Window::load() {
    char_sur  = SDL_LoadBMP("res/smile.bmp");
    if(char_sur == nullptr) return false;

    char_text = SDL_CreateTextureFromSurface(ren, char_sur);
    if(char_text == nullptr) return false;

    return true;
}

bool Window::update() {
    srand(time(0));
    gameRunning = true; // true if game loop is going
    SDL_Event e; // event handler

    // variables to count time between ticks
    Uint64 prevFrame = SDL_GetTicks64(); 
    Uint64 nextFrame;

    while (gameRunning) // main loop
    {
        ///event handle///
        SDL_PollEvent(&e);
        switch (e.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;
        }

        ///fps lock///
        nextFrame = SDL_GetTicks64();
        if(nextFrame - prevFrame < FRAME_TIME) {
            continue;
        }
        prevFrame = nextFrame;

        ///screen render///
        SDL_RenderClear(ren);
        SDL_Rect dstrect = { rand() % 1000, rand() % 1000, 50, 50 };
        SDL_RenderCopy(ren, char_text, NULL, &dstrect);
        SDL_RenderPresent(ren);
    }
    return true;
}
bool Window::quit() {
    SDL_DestroyTexture(char_text);
    SDL_FreeSurface(char_sur);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    return true;
}