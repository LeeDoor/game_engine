#pragma once
#include <SDL.h>
#include <memory>

//interface of all drawable components
class Drawable {
public:
    virtual void draw(SDL_Renderer*) = 0;
};

typedef std::shared_ptr<Drawable> DrawableShar;