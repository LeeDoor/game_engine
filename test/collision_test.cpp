#include "physics.hpp"
#include <iostream>

int main() {
    SDL_Rect *r1 = new SDL_Rect {0, 0, 2, 5}, 
    *r2 = new SDL_Rect {1, 2, 3, 5};
    Direction a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != Direction::Right) return 1;

    r1 = new SDL_Rect {0, 0, 2, 5};
    r2 = new SDL_Rect {1, 4, 3, 5};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != Direction::Right) return 1;

    r1 = new SDL_Rect {1, 1, 5, 3};
    r2 = new SDL_Rect {3, 2, 2, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(2)\n";
    if(a != Direction::Down) return 1;

    r1 = new SDL_Rect {3, 2, 2, 3};
    r2 = new SDL_Rect {1, 1, 5, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(0)\n";
    if(a != Direction::Up) return 1;

    r1 = new SDL_Rect {0, 0, 4, 3};
    r2 = new SDL_Rect {3, 1, 3, 1};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != Direction::Right) return 1;

    r1 = new SDL_Rect {3, 1, 3, 1};
    r2 = new SDL_Rect {0, 0, 4, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != Direction::Left) return 1;

    r1 = new SDL_Rect {0, 0, 3, 3};
    r2 = new SDL_Rect {5, 0, 3, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(4)\n";
    if(a != Direction::None) return 1;

    r1 = new SDL_Rect {0, 0, 5, 5};
    r2 = new SDL_Rect {1, 1, 2, 2};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(4)\n";
    if(a != Direction::None) return 1;
    
    r1 = new SDL_Rect {1, 1, 5, 5};
    r2 = new SDL_Rect {0, 2, 2, 2};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != Direction::Left) return 1;
    
    r1 = new SDL_Rect {0, 0, 3, 3};
    r2 = new SDL_Rect {2, 1, 6, 6};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != Direction::Right) return 1;
    
    
    
    
    return 0;
}