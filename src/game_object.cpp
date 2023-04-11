#include "game_object.hpp"

bool GameObject::init(Vector2iPtr pos_) {
    pos = std::move(pos_);
    return true;
}