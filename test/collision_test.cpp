#include "physics.hpp"
#include <iostream>

int main() {
    SDL_Rect r1 {0, 0, 2, 5}, 
    r2 {1, 2, 3, 5};
    int a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != 1) return 1;

    r1 = SDL_Rect {0, 0, 2, 5};
    r2 = SDL_Rect {1, 4, 3, 5};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != 1) return 1;

    r1 = SDL_Rect {1, 1, 5, 3};
    r2 = SDL_Rect {3, 2, 2, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(2)\n";
    if(a != 2) return 1;

    r1 = SDL_Rect {3, 2, 2, 3};
    r2 = SDL_Rect {1, 1, 5, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(0)\n";
    if(a != 0) return 1;

    r1 = SDL_Rect {0, 0, 4, 3};
    r2 = SDL_Rect {3, 1, 3, 1};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(1)\n";
    if(a != 1) return 1;
    

    r1 = SDL_Rect {3, 1, 3, 1};
    r2 = SDL_Rect {0, 0, 4, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != 3) return 1;

    r1 = SDL_Rect {0, 0, 3, 3};
    r2 = SDL_Rect {5, 0, 3, 3};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(4)\n";
    if(a != 4) return 1;

    r1 = SDL_Rect {0, 0, 5, 5};
    r2 = SDL_Rect {1, 1, 2, 2};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(4)\n";
    if(a != 4) return 1;
    
    r1 = SDL_Rect {1, 1, 5, 5};
    r2 = SDL_Rect {0, 2, 2, 2};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != 3) return 1;
    
    r1 = SDL_Rect {0, 0, 3, 3};
    r2 = SDL_Rect {2, 1, 6, 6};
    a = Physics::isCollide(r1, r2);   
    std::cout << a << "-(3)\n";
    if(a != 1) return 1;
    
    
    
    
    return 0;
}