#pragma once
#include "component.hpp"
#include "drawable.hpp"
#include "vector2.hpp"
#include "game_object.hpp"

//collider component. 
class Collider : public Component, public Drawable {
private:
    Vector2f size; //size of the collider
public:
    void init(GameObjectShar go_, Vector2f size_);
    void draw(SDL_Renderer*) override;
    void update() override {};
};