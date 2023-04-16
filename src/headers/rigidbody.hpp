#pragma once 
#include <SDL.h>
#include "vector2.hpp"
#include "game_object.hpp"
#include <memory>
#include <iostream>
#include "direction.hpp"
typedef std::unique_ptr<SDL_Rect> RectPtr;

class Rigidbody : public Component {
private:
protected:
    Vector2f size; // collider hitbox
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


    //returns direction where first collider collides second one
    static Direction isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize);
    static Direction isCollide(SDL_Rect first, SDL_Rect second);

    bool init(GameObjectShar go_);
    bool init(GameObjectShar go_, Vector2f size_, Vector2f dir_, float force_);
    void update () override;
    void print();
    void draw(SDL_Renderer* ren);
};

typedef std::shared_ptr<Rigidbody> PhysicShar;
typedef std::unique_ptr<Rigidbody> PhysicPtr;