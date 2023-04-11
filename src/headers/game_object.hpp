#pragma once
#include "vector2f.hpp"
#include <memory>

class GameObject {
protected:
    Vector2fPtr pos;
public:
    bool init(Vector2fPtr pos_);
};