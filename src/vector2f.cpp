#include "vector2f.hpp"
#include <cmath>

Vector2f::Vector2f(){
    x = 0;
    y = 0;
}
Vector2f::Vector2f(float x_, float y_) {
    x = x_;
    y = y_;
}

Vector2f Vector2f::Up = Vector2f {0, 1}; 
Vector2f Vector2f::Down = Vector2f{0, -1};
Vector2f Vector2f::Right = Vector2f{-1, 0};
Vector2f Vector2f::Left = Vector2f{1, 0};
Vector2f Vector2f::One = Vector2f{1, 1};
Vector2f Vector2f::Zero = Vector2f{0, 0};

void Vector2f::normalize() {
    float inv_length = 1.0f / len();
    *this *= inv_length;
}

float Vector2f::len() {
    return sqrt(lenpw2());
}
float Vector2f::lenpw2() {
    return x*x + y*y;
}

Vector2f Vector2f::operator + (const Vector2f& sec) {
    return Vector2f { x + sec.x, y + sec.y };
}
Vector2f Vector2f::operator - (const Vector2f& sec) {
    return Vector2f { x - sec.x, y - sec.y };
}
Vector2f Vector2f::operator * (float m) {
    return Vector2f { x * m, y * m };
}

void Vector2f::operator += (const Vector2f& sec) {
    x += sec.x;
    y += sec.y;
}
void Vector2f::operator -= (const Vector2f& sec) {
    x -= sec.x;
    y -= sec.y;
}
void Vector2f::operator *= (float m) {
    x *= m;
    y *= m;
}

bool Vector2f::operator > (Vector2f sec) {
    return lenpw2() > sec.lenpw2();
}
bool Vector2f::operator < (Vector2f sec) {
    return lenpw2() < sec.lenpw2();
}
bool Vector2f::operator >= (Vector2f sec) {
    return lenpw2() >= sec.lenpw2();
}
bool Vector2f::operator <= (Vector2f sec) {
    return lenpw2() <= sec.lenpw2();
}
bool Vector2f::operator == (Vector2f sec) {
    return lenpw2() == sec.lenpw2();
}
bool Vector2f::operator != (Vector2f sec) {
    return lenpw2() != sec.lenpw2();
}