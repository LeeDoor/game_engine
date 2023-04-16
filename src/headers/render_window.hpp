#pragma once
#include <SDL.h>
#include <vector>
#include "game_object.hpp"
#include "go_director.hpp"

class RenderWindow {
public:
    ~RenderWindow();

    //initialize function. creates window and renderer
    void init(const char *title, int x, int y, Uint32 flags);
    //clears memory
    void quit();
    //draws given elements
    void draw(std::vector<DrawableShar>);

    void present(); // presents all elements drawn
    void clear(); // clears renderer

    SDL_Renderer* getRenderer();
private:
    const int SCR_W = 1000; // window width
    const int SCR_H = 1000; // window height

    SDL_Window* win = nullptr; // main window
    SDL_Renderer* ren = nullptr; // window renderer
};

typedef std::shared_ptr<RenderWindow> RenderWindowShar;