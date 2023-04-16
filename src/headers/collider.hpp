#pragma once
#include "component.hpp"
#include "drawable.hpp"
#include "vector2.hpp"
#include "game_object.hpp"
#include "direction.hpp"

//collider component. 
class Collider : public Component, public Drawable {
private:
    Vector2f size; //size of the collider
public:
    void init(GameObjectShar go_, Vector2f size_);
    void draw(SDL_Renderer*) override;
    void update() override {};
    //where collide happened and how deep collider is in
    void collideFrom(Direction side, int depth); 
    SDL_Rect* getRect();
};

typedef std::shared_ptr<Collider> ColliderShar;