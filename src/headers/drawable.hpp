#pragma once
#include <SDL.h>

//abstract class for each object which can be drawn
class Drawable {
protected:
    SDL_Texture* text; // texture object of this class
    const char* pathToImage; // path to texture image

public:
    bool init(SDL_Renderer* ren, const char* pathToImage_) { // creates texture according to image path
        pathToImage = pathToImage_;
        SDL_Surface* sur = SDL_LoadBMP(pathToImage);
        if(sur == NULL) return false;

        text = SDL_CreateTextureFromSurface(ren, sur);
        if(text == NULL) return false;
        SDL_FreeSurface(sur);
        return true;
    } 
    virtual void draw(SDL_Renderer* ren) = 0; // drawing function. should be overrided for each object
};