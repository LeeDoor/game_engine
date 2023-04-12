#include "drawable.hpp"
#include "game_object.hpp"

bool Drawable::init(GameObjectShar go_, Vector2iPtr size_, SDL_Renderer* ren_, const char* pathToImage_) {
    if(!Component::init(go_))return false;

    textSize = std::move(size_);
    ren = ren_;
    pathToImage = pathToImage_;
        
    text = IMG_LoadTexture(ren, pathToImage_);
    if(text == NULL) return false;
    return true;
} 

void Drawable::draw() {
    Vector2iShar pos = go.lock()->getPos();
    SDL_RenderCopy(ren, text, NULL, new SDL_Rect {pos->x, pos->y, textSize->x, textSize->y});
}