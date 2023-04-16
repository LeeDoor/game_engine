#include "render_window.hpp"

RenderWindow::~RenderWindow() {
    quit();
}

void RenderWindow::init(const char *title, int x, int y, Uint32 flags) {
    win = SDL_CreateWindow(title, x, y, SCR_W, SCR_H, flags);
    ren = SDL_CreateRenderer(win, -1, 0);
}

void RenderWindow::quit() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

void RenderWindow::draw(std::vector<DrawableShar> vec) {
    for(DrawableShar el : vec) {
        el->draw(ren);
    }
}

void RenderWindow::present() {
    SDL_RenderPresent(ren);
}
void RenderWindow::clear() { 
    SDL_RenderClear(ren);
}

SDL_Renderer* RenderWindow::getRenderer() {
    return ren;
}