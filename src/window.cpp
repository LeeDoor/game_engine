#include "window.hpp"
#include <ctime>

void Window::init() {
    renderWindow = std::make_shared<RenderWindow>();
    renderWindow->init("time shifter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0);
    load();
    update();
}

void Window::load() {
    SDL_Renderer* ren = renderWindow->getRenderer();
    GameObjectDirector dir;
    dir.buildPlayer(ren);
    GameObjectShar hero = dir.getObject();
    toDraw.push_back(hero->getComponent<Drawable>());
    physics.push_back(hero->getComponent<Physic>());
    objects.push_back(hero);
}

void Window::update() {
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
        renderWindow->clear();
        for(GameObjectShar cur : objects){ // cycle to update every gameobject
            cur->update();
        }
        renderWindow->draw(toDraw);
        renderWindow->present();
    }
}