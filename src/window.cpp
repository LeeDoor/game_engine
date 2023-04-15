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
    GameObjectDirector dir;
    dir.buildPlayer(ren);
    GameObjectShar hero = dir.getObject();
    toDraw.push_back(hero->getComponent<Drawable>());
    physics.push_back(hero->getComponent<Physic>());
    objects.push_back(hero);
    return true;
}

bool Window::update() {
    srand(time(0));
    gameRunning = true; // true if game loop is going
    bool physicDraw = true; // draw physic colliders
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
        for(GameObjectShar cur : objects){ // cycle to update every gameobject
            cur->update();
        }
        for(DrawableShar cur : toDraw){ // cycle to draw each drawable element in vector
            cur->draw();
        }
        if(physicDraw) {
            for(PhysicShar cur : physics) {
                cur->draw(ren);
            }
        }
        SDL_RenderPresent(ren);
    }
    return true;
}
bool Window::quit() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    return true;
}