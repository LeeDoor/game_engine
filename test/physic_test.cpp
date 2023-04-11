#include <iostream>
#include "physic.hpp"

int main() {
    Physic a;
    RectPtr rect = std::make_unique<SDL_Rect>(SDL_Rect{5,5,5,5});
    Vector2fPtr vec = std::make_unique<Vector2f>(Vector2f{5,5});
    Vector2iPtr pos = std::make_unique<Vector2i>(Vector2i{1,2});
    if(!a.init(std::move(pos), std::move(rect), std::move(vec), 20))return 1;
    std::cout << "object inited\n\n";

    a.print();

    a.update();
    a.update();
    a.update();

    a.print();

    return 0;
}