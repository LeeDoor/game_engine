#include "hero.hpp"

Hero::Hero(){
    xpos = 5;
    ypos = 5;
}

Hero::~Hero(){
    SDL_DestroyTexture(text);
}

void Hero::draw(SDL_Renderer* ren) {
    SDL_Rect dstrect = { rand() % 1000, rand() % 1000, 50, 50 };
    SDL_RenderCopy(ren, text, NULL, &dstrect);
}