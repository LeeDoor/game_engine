#include "physic.hpp"

float Physic::GRAVITY_FORCE = 3;
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

int Physic::isCollide(Vector2f fPos, Vector2f fSize, Vector2f sPos, Vector2f sSize) {
    return isCollide(SDL_Rect{(int)fPos.x, (int)fPos.y, (int)fSize.x, (int)fSize.y}, 
                     SDL_Rect{(int)sPos.x, (int)sPos.y, (int)sSize.x, (int)sSize.y});
}
int Physic::isCollide(SDL_Rect first, SDL_Rect second){
    if(first.y < second.y + second.h && first.y > second.y) return 0;
    if(first.x < second.x + second.w && first.x > second.x) return 1;
    if(first.y + first.h > second.y && first.y+first.h < second.y + second.h) return 2;
    if(first.x + first.w > second.x && first.x + first.w < second.x + second.w) return 3;
    return 4;
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
    force = newPos.len();
    newPos.normalize();
    dir = newPos;
}
void Physic::print(){
    Vector2f pos = go.lock()->getPos();
    std::cout << "collider: " << pos.x << ' ' << pos.y << ' ' << size.x << " " << size.y << "\n"
        << "direction: " << dir.x << " " << dir.y << '\n'
        << "force: " << force << "\n";
}