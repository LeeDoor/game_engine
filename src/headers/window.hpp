#pragma once
#include <SDL.h>
#include <vector>
#include "game_object.hpp"
#include "go_director.hpp"
#include "render_window.hpp"

class Window {
public:
    //initialize function. creates window and renderer
    void init();
private:
    void update(); //main game loop
    //loads textures
    void load();

    RenderWindowShar renderWindow;

    std::vector<DrawableShar> toDraw;
    std::vector<PhysicShar> physics;
    std::vector<GameObjectShar> objects;

    const int MAX_FPS = 20; // max fps
    const double FRAME_TIME = 1000/(double)MAX_FPS; // time between frame changings

    bool gameRunning = false; // is game running variable
};