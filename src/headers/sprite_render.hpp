#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "drawable.hpp"
#include "component.hpp"
#include "vector2.hpp"

//abstract class for each object which can be drawn
class SpriteRender : public Component, public Drawable {
protected:
    SDL_Texture* text; // texture object of this class
    const char* pathToImage; // path to texture image
    Vector2f textSize;
public:
    // creates texture according to image path
    bool init(GameObjectShar go_, Vector2f size_, SDL_Renderer* ren_, const char* pathToImage_);
    void draw(SDL_Renderer*) override; // drawing update function
    void update() override {}
};

typedef std::unique_ptr<SpriteRender> SpriteRendererPtr;
typedef std::shared_ptr<SpriteRender> SpriteRendererShar;