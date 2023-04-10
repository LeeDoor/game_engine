#include "hero.hpp"

Hero::Hero(){
    x = 5;
    y = 5;
}

Hero::~Hero(){
    SDL_DestroyTexture(text);
}

void Hero::draw(SDL_Renderer* ren) {
    SDL_Rect dstrect = { x, y, w, h };
    SDL_RenderCopy(ren, text, NULL, &dstrect);
}