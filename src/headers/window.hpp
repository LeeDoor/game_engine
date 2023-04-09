#pragma once
#include <SDL.h>

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


    const int SCR_W = 1000; // window width
    const int SCR_H = 1000; // window height

    bool gameRunning = false; // is game running variable

    SDL_Window* win = nullptr; // main window
    SDL_Renderer* ren = nullptr; // window renderer

    SDL_Surface* char_sur = nullptr; // main character surface
    SDL_Texture* char_text = nullptr; // main character texture
};