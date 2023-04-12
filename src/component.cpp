#include "component.hpp"
#include "game_object.hpp"

bool Component::init(GameObjectShar go_) {
    go = go_;
    return true;
}