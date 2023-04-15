#pragma once 
#include <SDL.h>
#include "vector2.hpp"
#include "game_object.hpp"
#include <memory>
#include <iostream>
#include "direction.hpp"
typedef std::unique_ptr<SDL_Rect> RectPtr;

class Physic : public Component {
private:
protected:
    Vector2i size; // collider hitbox
    Vector2f dir; // direction of force
    float force; // force value
    
public:
    static float GRAVITY_FORCE;
    static Vector2f GRAVITY_DIR;

    /// access methods 
    float getForce();
    void setForce(float force_);

    Vector2f getDir();
    void setDir(Vector2f dir_);

    /////////

    //    0
    //  1 4 3
    //    2
    // returns 0 if collision is upside, 1 if leftside, 2 if downside and 3 if rightside
    static Direction isCollide(Vector2i fPos, Vector2i fSize, Vector2i sPos, Vector2i sSize);
    static Direction isCollide(SDL_Rect first, SDL_Rect second);

    bool init(GameObjectShar go_);
    bool init(GameObjectShar go_, Vector2i size_, Vector2f dir_, float force_);
    void update () override;
    void print();
    void draw(SDL_Renderer* ren);
};

typedef std::shared_ptr<Physic> PhysicShar;
typedef std::unique_ptr<Physic> PhysicPtr;