#pragma once
#include "vector2.hpp"
#include "SDL.h"
#include "direction.hpp"

//static class of physics operations
class Physics {
public:
    static float GRAVITY_FORCE;
    static Vector2f GRAVITY_DIR;

    //returns direction where first collider collides second one
    static Direction isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize);
    static Direction isCollide(SDL_Rect first, SDL_Rect second);
};