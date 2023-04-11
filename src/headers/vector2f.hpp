#pragma once
#include <memory>

//standard two-dimentional vector
class Vector2f{
public:
    float x, y; // coordinates

    Vector2f();
    Vector2f(float x_, float y_);

    static Vector2f Up;
    static Vector2f Down;
    static Vector2f Right;
    static Vector2f Left;
    static Vector2f One;
    static Vector2f Zero;

    void normalize(); // normalizes current vector

    float len(); // length of vector
    float lenpw2(); // length of vector in second power. needed to compare two lengths without counting sqrt

    /// operators
    Vector2f operator + (const Vector2f& sec);
    Vector2f operator - (const Vector2f& sec);
    Vector2f operator * (float m);

    void operator += (const Vector2f& sec);
    void operator -= (const Vector2f& sec);
    void operator *= (float m);

    bool operator > (Vector2f sec);
    bool operator < (Vector2f sec);
    bool operator >= (Vector2f sec);
    bool operator <= (Vector2f sec);
    bool operator == (Vector2f sec);
    bool operator != (Vector2f sec);
};

typedef std::unique_ptr<Vector2f> Vector2fPtr;