#include "vector2f.hpp"
#include "iostream"

int main() {
    Vector2f v1 { 2, 5 };
    Vector2f v2 { 4, -2 };
    if( v1 + v2 != Vector2f {6, 3} ) return 1;
    if( v1 - v2 != Vector2f {-2, 7} ) return 1;
    if( v1 * 5 != Vector2f {10, 25} ) return 1;

    Vector2f v3 {3, 4};
    if( v3.len() != 5) return 1;
    if( v3.lenpw2() != 25) return 1;

    v3.normalize();
    if(v3 != Vector2f {0.6f, 0.8f }) return 1;
    return 0;
}