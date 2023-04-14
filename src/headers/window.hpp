#pragma once
#include <SDL.h>
#include <vector>
#include "game_object.hpp"
#include "go_builder.hpp"

class Window {
public:
    Window(); // default constructor
    ~Window(); // destructor

    bool update(); //main game loop
private:
    //initialize function. creates window and renderer
    bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
    //loads textures
    bool load();
    //clears memory
    bool quit();


    std::vector<DrawableShar> toDraw;
    std::vector<GameObjectShar> objects;

    const int SCR_W = 1000; // window width
    const int SCR_H = 1000; // window height

    const int MAX_FPS = 20; // max fps
    const double FRAME_TIME = 1000/(double)MAX_FPS; // time between frame changings

    bool gameRunning = false; // is game running variable

    SDL_Window* win = nullptr; // main window
    SDL_Renderer* ren = nullptr; // window renderer
};