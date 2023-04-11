#include "drawable.hpp"

bool Drawable::init(SDL_Renderer* ren, const char* pathToImage_, Vector2fPtr pos_) {
    if(!GameObject::init(std::move(pos_)))return false;
    pathToImage = pathToImage_;
        
    text = IMG_LoadTexture(ren, pathToImage_);
    if(text == NULL) return false;
    return true;
} 