#pragma once
#include <SDL.h>

class Window {
public:
    Window();
    ~Window();

    bool update(); 
private:
    bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
    bool load();
    bool quit();
    const int SCR_W = 1000;
    const int SCR_H = 1000;

    bool gameRunning = false;

    SDL_Window* win = nullptr;
    SDL_Renderer* ren = nullptr;
    SDL_Event* e = nullptr;

    SDL_Surface* char_sur = nullptr;
    SDL_Texture* char_text = nullptr;
};