#include "game_object.hpp"

bool GameObject::init(Vector2f pos_) {
    pos = pos_;
    return true;
}

Vector2f GameObject::getPos() {
    return pos;
}

void GameObject::update() {
    for(ComponentShar comp : components) {
        comp->update();
    } 
}