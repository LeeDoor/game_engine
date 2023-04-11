#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "game_object.hpp"
//abstract class for each object which can be drawn
class Drawable : public GameObject {
protected:
    SDL_Texture* text; // texture object of this class
    const char* pathToImage; // path to texture image

public:
    bool init(SDL_Renderer* ren, const char* pathToImage_, Vector2fPtr pos_) { // creates texture according to image path
        GameObject::init(std::move(pos_));
        pathToImage = pathToImage_;
        
        text = IMG_LoadTexture(ren, pathToImage_);
        if(text == NULL) return false;
        return true;
    } 
    virtual void draw(SDL_Renderer* ren) = 0; // drawing function. should be overrided for each object
};