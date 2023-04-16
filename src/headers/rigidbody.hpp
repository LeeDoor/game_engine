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
    float elasticity; // value where 0 never bounces and 1 bounces with losing minimal force. cannot be less than 0

    void setElasticity(float el_);
public:
    /// access methods 
    float getForce();
    void setForce(float force_);

    Vector2f getDir();
    void setDir(Vector2f dir_);

    float getElasticity();

    /////////
    bool init(GameObjectShar go_, Vector2f dir_ = Vector2f::STD[Direction::Up], float force_ = 0, float elasticity_ = 0.5f);
    void update () override;
    void collisionReact(Direction dir, int depth);
};

typedef std::shared_ptr<Rigidbody> RigidbodyShar;
typedef std::unique_ptr<Rigidbody> RigidbodyPtr;