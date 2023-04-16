#pragma once
#include "vector2.hpp"
#include "SDL.h"
#include "direction.hpp"

//static class of physics operations
class Physics {
public:
    static float GRAVITY_FORCE;
    static Vector2f GRAVITY_DIR;
    static float MINIMAL_FORCE;

    //returns direction where first collider collides second one
    static std::pair<Direction, int> isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize);
    static std::pair<Direction, int> isCollide(SDL_Rect* first, SDL_Rect* second);
};