#include "game_object.hpp"

bool GameObject::init(Vector2i pos_) {
    pos = pos_;
    return true;
}

Vector2i GameObject::getPos() {
    return pos;
}

void GameObject::update() {
    for(ComponentShar comp : components) {
        comp->update();
    } 
}