#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "component.hpp"
#include "vector2.hpp"

//abstract class for each object which can be drawn
class Drawable : public Component {
protected:
    SDL_Renderer* ren; // renderer for drawing
    SDL_Texture* text; // texture object of this class
    const char* pathToImage; // path to texture image
    Vector2i textSize;
public:
    // creates texture according to image path
    bool init(GameObjectShar go_, Vector2i size_, SDL_Renderer* ren_, const char* pathToImage_);
    void draw(); // drawing update function
    void update() override {}
};

typedef std::unique_ptr<Drawable> DrawablePtr;
typedef std::shared_ptr<Drawable> DrawableShar;