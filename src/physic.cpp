#include "physic.hpp"
#include <map>
#include <algorithm>

float Physic::GRAVITY_FORCE = 1.0f;
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

Direction Physic::isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize) {
    return isCollide(SDL_Rect{(int)fPos.x, (int)fPos.y, (int)fSize.x, (int)fSize.y}, 
                     SDL_Rect{(int)sPos.x, (int)sPos.y, (int)sSize.x, (int)sSize.y});
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
    return init(go_, Vector2f{ 1, 1 }, Vector2f{1, 1}, 0);
}
bool Physic::init(GameObjectShar go_, Vector2f size_, Vector2f dir_, float force_) {
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
    go.lock()->pos += Vector2f(newPos.x, newPos.y);
    setForce(newPos.len());
    setDir(newPos);
}
void Physic::print(){
    Vector2f pos = go.lock()->getPos();
    std::cout << "collider: " << pos.x << ' ' << pos.y << ' ' << size.x << " " << size.y << "\n"
        << "direction: " << dir.x << " " << dir.y << '\n'
        << "force: " << force << "\n";
}

void Physic::draw(SDL_Renderer* ren) {
    Vector2f pos = go.lock()->getPos();
    SDL_SetRenderDrawColor(ren, 38, 255, 74, 255);
    SDL_RenderDrawRect(ren, new SDL_Rect{(int)pos.x, (int)pos.y, (int)size.x, (int)size.y});
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}