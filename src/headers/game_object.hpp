#pragma once
#include "vector2f.hpp"
#include <memory>

class GameObject {
protected:
    Vector2fPtr pos;
public:
    void init(Vector2fPtr pos_) {
        pos = std::move(pos_);
    }
};