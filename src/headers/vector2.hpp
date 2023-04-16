#pragma once
#include <memory>
#include <cmath>
#include <map>
#include "direction.hpp"

//standard two-dimentional vector
template<typename T>
class Vector2{
public:
    T x, y; // coordinates

    Vector2() {
        x = 0;
        y = 0;
    }
    Vector2(T x_, T y_) : x(x_), y(y_) {}

    static std::map<Direction, Vector2<float>> STD;

    // normalizes current vector
    void normalize() {
        if(*this == STD[Direction::None]) return;
        float inv_length = 1.0f / len();
        *this *= inv_length;
    }
    // length of vector
    float len() {
        return sqrt(lenpw2());
    } 
    // length of vector in second power. needed to compare two lengths without counting sqrt
    float lenpw2() {
        return x*x + y*y;
    } 

    /// operators
    Vector2 operator + (const Vector2& sec){
        return Vector2 { x + sec.x, y + sec.y };
    }
    Vector2 operator - (const Vector2& sec){
        return Vector2 { x - sec.x, y - sec.y };
    }
    Vector2 operator * (float m) {
        return Vector2 { x * m, y * m };
    }
    void operator += (const Vector2& sec) {
        x += sec.x;
        y += sec.y;
    }
    void operator -= (const Vector2& sec) {
        x -= sec.x;
        y -= sec.y;
    }
    void operator *= (float m) {
        x *= m;
        y *= m;
    }

    bool operator > (Vector2 sec) {
        return lenpw2() > sec.lenpw2();
    }
    bool operator < (Vector2 sec) {
        return lenpw2() < sec.lenpw2();
    }
    bool operator >= (Vector2 sec) {
        return lenpw2() >= sec.lenpw2();
    }
    bool operator <= (Vector2 sec) {
        return lenpw2() <= sec.lenpw2();
    }
    bool operator == (Vector2 sec) {
        return lenpw2() == sec.lenpw2();
    }
    bool operator != (Vector2 sec) {
        return lenpw2() != sec.lenpw2();
    }
};

typedef Vector2<float> Vector2f;

template<typename T>
std::map<Direction, Vector2f> Vector2<T>::STD {
    {Direction::Up, Vector2f{0, -1}},
    {Direction::Down, Vector2f{0, 1}},
    {Direction::Right, Vector2f{1, 0}},
    {Direction::Left, Vector2f{-1, 0}},
    {Direction::None, Vector2f{0, 0}}
};

// template<typename T>
// Vector2<float> Vector2<T>::Up = 
// template<typename T>
// Vector2<float> Vector2<T>::Down = 
// template<typename T>
// Vector2<float> Vector2<T>::Right = 
// template<typename T>
// Vector2<float> Vector2<T>::Left = 
// template<typename T>
// Vector2<float> Vector2<T>::Zero = 
