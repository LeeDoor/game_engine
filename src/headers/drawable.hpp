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
    // creates texture according to image path
    bool init(SDL_Renderer* ren, const char* pathToImage_, Vector2iPtr pos_);
    virtual void draw(SDL_Renderer* ren) = 0; // drawing function. should be overrided for each object
};