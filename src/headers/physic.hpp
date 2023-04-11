#pragma once 
#include <SDL.h>
#include "vector2f.hpp"
#include "game_object.hpp"
#include <memory>
#include <iostream>

typedef std::unique_ptr<SDL_Rect> RectPtr;

class Physic : public GameObject {
private:
protected:
    RectPtr coll; // collider hitbox
    Vector2fPtr dir; // direction of force
    float force; // force value
    
public:
    const float GRAVITY_FORCE = 5;
    const Vector2f GRAVITY_DIR = Vector2f::Down;

    /// access methods 
    float getForce();
    void setForce(float force_);

    Vector2f* getDir();
    void setDir(Vector2fPtr dir_);

    /////////

    //    0
    //  1 4 3
    //    2
    // returns 0 if collision is upside, 1 if leftside, 2 if downside and 3 if rightside
    static int isCollide(SDL_Rect& first, SDL_Rect& second);

    bool init();
    bool init(Vector2fPtr pos_, RectPtr coll_, Vector2fPtr dir_, float force_);
    void update (int collision = 4);
    void print();
};