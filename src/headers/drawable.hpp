#pragma once
#include <SDL.h>
#include <SDL_image.h>

//abstract class for each object which can be drawn
class Drawable {
protected:
    SDL_Texture* text; // texture object of this class
    const char* pathToImage; // path to texture image

public:
    bool init(SDL_Renderer* ren, const char* pathToImage_) { // creates texture according to image path
        pathToImage = pathToImage_;
        
        text = IMG_LoadTexture(ren, pathToImage_);
        if(text == NULL) return false;
        return true;
    } 
    virtual void draw(SDL_Renderer* ren) = 0; // drawing function. should be overrided for each object
};