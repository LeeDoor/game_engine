#include "game_object.hpp"

bool GameObject::init(Vector2iPtr pos_) {
    pos = std::move(pos_);
    return true;
}

Vector2iShar GameObject::getPos() {
    return pos;
}

void GameObject::update() {
    for(ComponentShar comp : components) {
        comp->update();
    } 
}