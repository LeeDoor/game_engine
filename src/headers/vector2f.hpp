#pragma once
#include <memory>
#include <cmath>
#include <iostream>
//standard two-dimentional vector
class Vector2f {
public:
    float x, y; // coordinates

    Vector2f() {
        x = 0;
        y = 0;
    }
    Vector2f(float x_, float y_) : x(x_), y(y_) {}

    const static Vector2f Up; 
    const static Vector2f Down;
    const static Vector2f Right;
    const static Vector2f Left;
    const static Vector2f One;
    const static Vector2f Zero;

    // normalizes current vector
    void normalize() {
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
    Vector2f operator + (const Vector2f& sec){
        return Vector2f { x + sec.x, y + sec.y };
    }
    Vector2f operator - (const Vector2f& sec){
        return Vector2f { x - sec.x, y - sec.y };
    }
    Vector2f operator * (float m) {
        Vector2f a { x * m, y * m };
        std::cout << x << " " << y << " " << m << "\n"<< x*m << " " << y*m << "\n" << a.x << " " << a.y << "\n";
        return a;
    }
    void operator += (const Vector2f& sec) {
        x += sec.x;
        y += sec.y;
    }
    void operator -= (const Vector2f& sec) {
        x -= sec.x;
        y -= sec.y;
    }
    void operator *= (const float m) {
        x *= m;
        y *= m;
    }

    bool operator > (Vector2f sec) {
        return lenpw2() > sec.lenpw2();
    }const 
    bool operator < (Vector2f sec) {
        return lenpw2() < sec.lenpw2();
    }
    bool operator >= (Vector2f sec) {
        return lenpw2() >= sec.lenpw2();
    }
    bool operator <= (Vector2f sec) {
        return lenpw2() <= sec.lenpw2();
    }
    bool operator == (Vector2f sec) {
        return lenpw2() == sec.lenpw2();
    }
    bool operator != (Vector2f sec) {
        return lenpw2() != sec.lenpw2();
    }
};