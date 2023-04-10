#pragma once

//standard two-dimentional vector
class Vector2f{
public:
    float x, y; // coordinates

    void normalize(); // normalizes current vector

    float len(); // length of vector
    float lenpw2(); // length of vector in second power. needed to compare two lengths without counting sqrt

    /// operators
    Vector2f operator + (const Vector2f& sec);
    Vector2f operator - (const Vector2f& sec);
    Vector2f operator * (int m);

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