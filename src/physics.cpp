#include "physics.hpp"
#include <map>
#include <algorithm>
#include <iostream>

float Physics::GRAVITY_FORCE = 0.5f;
Vector2f Physics::GRAVITY_DIR = Vector2f::STD[Direction::Down];

std::pair<Direction, int> Physics::isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize) {
    return isCollide(new SDL_Rect{(int)fPos.x, (int)fPos.y, (int)fSize.x, (int)fSize.y}, 
                     new SDL_Rect{(int)sPos.x, (int)sPos.y, (int)sSize.x, (int)sSize.y});
}
std::pair<Direction, int> Physics::isCollide(SDL_Rect* first, SDL_Rect* second){
    std::map<Direction, int> dist;

    //counts distance how deep figure is in for each side
    if(first->y < second->y + second->h && first->y > second->y) 
        dist[Up] = second->y + second->h - first->y;
    
    if(first->x < second->x + second->w && first->x > second->x) {
        dist[Left] = second->x + second->w - first->x;
    }
    if(first->y + first->h > second->y && first->y+first->h < second->y + second->h) {
        dist[Down] = first->y + first->h - second->y;
    }
    if(first->x + first->w > second->x && first->x + first->w < second->x + second->w) {
        dist[Right] = first->x + first->w - second->x;
    }
    if(dist.size() <= 1) 
        return std::make_pair(Direction::None, 0);
    /*if(dist.size() == 3){
        for(auto pair : dist) {
            std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }*/

    //if figure collides left and right, it means figure is inside. should be removed both sides
    if(dist.contains(Direction::Left) && dist.contains(Direction::Right)) {
        auto it = dist.find (Direction::Left);
        dist.erase (it);
        it = dist.find (Direction::Right); 
        dist.erase (it);
    }
    if(dist.contains(Direction::Up) && dist.contains(Direction::Down)) {
        auto it = dist.find (Direction::Up);
        dist.erase (it);
        it = dist.find (Direction::Down); 
        dist.erase (it);
    } 
    if(dist.size() == 0)
        return std::make_pair(Direction::None, 0);

    //find minimal distance to border and return its side
    std::pair <Direction, int> min = *std::min_element(dist.begin(), dist.end(), 
                [](const auto& l, const auto& r) { return l.second < r.second; });
    return min;

}