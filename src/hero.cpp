#include "hero.hpp"

Hero::Hero() {
}

Hero::~Hero(){
    SDL_DestroyTexture(text);
}

bool Hero::init(SDL_Renderer* ren, const char* text, Vector2iPtr pos_){
    if(!Drawable::init(ren, text, std::move(pos_)))return false;
    return true;
}
void Hero::draw(SDL_Renderer* ren) {
    SDL_Rect dstrect = { pos->x, pos->y, w, h };
    SDL_RenderCopy(ren, text, NULL, &dstrect);
}