#pragma once 
#include <SDL.h>
#include "vector2.hpp"
#include "game_object.hpp"
#include <memory>
#include <iostream>

typedef std::unique_ptr<SDL_Rect> RectPtr;

class Rigidbody : public Component {
private:
protected:
    Vector2f dir; // direction of force
    float force; // force value
    
public:
    /// access methods 
    float getForce();
    void setForce(float force_);

    Vector2f getDir();
    void setDir(Vector2f dir_);

    /////////
    bool init(GameObjectShar go_);
    bool init(GameObjectShar go_, Vector2f dir_, float force_);
    void update () override;
};

typedef std::shared_ptr<Rigidbody> RigidbodyShar;
typedef std::unique_ptr<Rigidbody> RigidbodyPtr;