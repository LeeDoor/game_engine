#include "physic.hpp"
#include <map>
#include <algorithm>

float Physic::GRAVITY_FORCE = 0.2;
Vector2f Physic::GRAVITY_DIR = Vector2f::Down;

float Physic::getForce() { 
    return force; 
}
void Physic::setForce(float force_) { 
    force = force_; 
}

Vector2f Physic::getDir() {
    return dir;
}
void Physic::setDir(Vector2f dir_) {
    dir_.normalize();
    dir = dir_;
}

Direction Physic::isCollide(Vector2i fPos, Vector2i fSize, Vector2i sPos, Vector2i sSize) {
    return isCollide(SDL_Rect{fPos.x, fPos.y, fSize.x, fSize.y}, 
                     SDL_Rect{sPos.x, sPos.y, sSize.x, sSize.y});
}
Direction Physic::isCollide(SDL_Rect first, SDL_Rect second){
    std::map<Direction, int> dist;

    //counts distance how deep figure is in for each side
    if(first.y < second.y + second.h && first.y > second.y) 
        dist[Up] = second.y + second.h - first.y;
    
    if(first.x < second.x + second.w && first.x > second.x) {
        dist[Left] = second.x + second.w - first.x;
    }
    if(first.y + first.h > second.y && first.y+first.h < second.y + second.h) {
        dist[Down] = first.y + first.h - second.y;
    }
    if(first.x + first.w > second.x && first.x + first.w < second.x + second.w) {
        dist[Right] = first.x + first.w - second.x;
    }
    if(dist.size() == 0)
        return Direction::None;
    
    //if figure collides left and right, it means figure is inside. should be removed both sides
    if(dist.contains(Direction::Left) && dist.contains(Direction::Right)) {
        dist[Left] = 999;
        dist[Right] = 999;
    }
    if(dist.contains(Direction::Up) && dist.contains(Direction::Down)) {
        dist[Up] = 999;
        dist[Down] = 999;
    }

    //find minimal distance to border and return its side
    std::pair <Direction, int> min = *std::min_element(dist.begin(), dist.end(), 
                [](const auto& l, const auto& r) { return l.second < r.second; });
    return min.first;

}
bool Physic::init(GameObjectShar go_) {
    return init(go_, Vector2i{ 1, 1 }, Vector2f{1, 1}, 0);
}
bool Physic::init(GameObjectShar go_, Vector2i size_, Vector2f dir_, float force_) {
    Component::init(go_);
    size = size_;
    setDir(dir_);
    setForce(force_);
    return true;
}   
void Physic::update () {
    int collision = 4;
    if(collision == 2){
        force = 0;
        dir = Vector2f::Zero;
        return;
    }
    Vector2f newPos = dir * force + GRAVITY_DIR * GRAVITY_FORCE;
    go.lock()->pos += Vector2i(newPos.x, newPos.y);
    force = newPos.len();
    newPos.normalize();
    dir = newPos;
}
void Physic::print(){
    Vector2i pos = go.lock()->getPos();
    std::cout << "collider: " << pos.x << ' ' << pos.y << ' ' << size.x << " " << size.y << "\n"
        << "direction: " << dir.x << " " << dir.y << '\n'
        << "force: " << force << "\n";
}

void Physic::draw(SDL_Renderer* ren) {
    Vector2i pos = go.lock()->getPos();
    SDL_SetRenderDrawColor(ren, 38, 255, 74, 255);
    SDL_RenderDrawRect(ren, new SDL_Rect{pos.x, pos.y, size.x, size.y});
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}