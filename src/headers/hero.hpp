#pragma once
#include "drawable.hpp"

class Hero : public Drawable {
public:
    Hero();
    ~Hero();
    
    void draw(SDL_Renderer* ren) override;
private:
    const int width = 40, height = 40;
    int xpos, ypos;

};