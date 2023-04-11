#pragma once
#include "drawable.hpp"
#include "vector2f.hpp"

class Hero : public Drawable {
public:
    Hero();
    ~Hero();
    
    bool init(SDL_Renderer* ren, const char* text, Vector2fPtr pos_);
    void draw(SDL_Renderer* ren) override;

private:
    const int w = 400, h = 400;

};