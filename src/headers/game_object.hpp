#pragma once
#include "vector2.hpp"
#include <memory>

class GameObject {
protected:
    Vector2iPtr pos;
public:
    bool init(Vector2iPtr pos_);
};