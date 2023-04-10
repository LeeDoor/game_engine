#pragma once
#include "drawable.hpp"

class Hero : public Drawable {
public:
    Hero();
    ~Hero();
    
    void draw(SDL_Renderer* ren) override;
private:
    const int w = 400, h = 400;
    int x, y;

};