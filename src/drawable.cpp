#include "drawable.hpp"
#include "game_object.hpp"

bool Drawable::init(GameObjectShar go_, Vector2f size_, SDL_Renderer* ren_, const char* pathToImage_) {
    if(!Component::init(go_))return false;

    textSize = size_;
    pathToImage = pathToImage_;
        
    text = IMG_LoadTexture(ren_, pathToImage_);
    if(text == NULL) return false;
    return true;
} 

void Drawable::draw(SDL_Renderer* ren) {
    Vector2f pos = go.lock()->getPos();
    SDL_RenderCopy(ren, text, NULL, new SDL_Rect {(int)pos.x, (int)pos.y, (int)textSize.x, (int)textSize.y});
}