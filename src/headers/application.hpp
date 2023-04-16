#pragma once
#include <SDL.h>
#include <vector>
#include "game_object.hpp"
#include "go_director.hpp"
#include "render_window.hpp"

class Application {
public:
    //initialize function. creates window and renderer
    void init();
private:
    void update(); //main game loop
    void load(); //loads gameobjects
    void collide(); //checks collision between all colliders 

    RenderWindowShar renderWindow;

    std::vector<DrawableShar> toDraw;
    std::vector<GameObjectShar> objects;
    std::vector<ColliderShar> colliders;

    const int MAX_FPS = 60; // max fps
    const double FRAME_TIME = 1000/(double)MAX_FPS; // time between frame changings

    bool gameRunning = false; // is game running variable
};