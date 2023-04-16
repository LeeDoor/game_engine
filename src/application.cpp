#include "application.hpp"
#include <ctime>
#include "physics.hpp"

//if defined, colliders will be drawn
#define COLLIDER_DRAW 

void Application::init() {
    renderWindow = std::make_shared<RenderWindow>();
    renderWindow->init("time shifter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0);
    load();
    update();
}

void Application::load() {
    SDL_Renderer* ren = renderWindow->getRenderer();
    GameObjectDirector dir;
    dir.buildPlayer(ren, Vector2f{500, 500});
    GameObjectShar hero = dir.getObject();
    toDraw.push_back(hero->getComponent<SpriteRender>());
    colliders.push_back(hero->getComponent<Collider>());
    objects.push_back(hero);

    dir.buildWall(ren, Vector2f{100, 800}, Vector2f {800, 100});
    GameObjectShar wall = dir.getObject();
    colliders.push_back(wall->getComponent<Collider>());
    objects.push_back(wall);
    toDraw.push_back(wall->getComponent<Collider>());

    dir.buildWall(ren, Vector2f{100, 100}, Vector2f {100, 800});
    wall = dir.getObject();
    colliders.push_back(wall->getComponent<Collider>());
    objects.push_back(wall);
    toDraw.push_back(wall->getComponent<Collider>());

    dir.buildWall(ren, Vector2f{800, 100}, Vector2f {100, 800});
    wall = dir.getObject();
    colliders.push_back(wall->getComponent<Collider>());
    objects.push_back(wall);

#ifdef COLLIDER_DRAW
    toDraw.push_back(hero->getComponent<Collider>());
    toDraw.push_back(wall->getComponent<Collider>());
#endif


}

void Application::collide() {
    for(auto it1 = colliders.begin(); it1 != colliders.end(); ++it1)  {
        for(auto it2 = it1 + 1; it2 != colliders.end(); ++it2) {
        auto pair = Physics::isCollide((*it1)->getRect(), (*it2)->getRect()); 
            if(pair.first != Direction::None) {
                (*it1)->collideFrom(pair.first, pair.second);
                (*it2)->collideFrom(INV_DIR(pair.first), pair.second);
            }
        }
    }
}

void Application::update() {
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

        ///screen update///
        for(GameObjectShar cur : objects){ // cycle to update every gameobject
            cur->update();
        }
        collide();
        ///screen render///

        renderWindow->clear();
        renderWindow->draw(toDraw);
        renderWindow->present();
    }
}