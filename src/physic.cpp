#include "physic.hpp"

float Physic::getForce() { 
    return force; 
}
void Physic::setForce(float force_) { 
    force = force_; 
}

Vector2f* Physic::getDir() {
    return dir.get();
}
void Physic::setDir(Vector2fPtr dir_) {
    dir_->normalize();
    dir = std::move(dir_);
}

int Physic::isCollide(SDL_Rect& first, SDL_Rect& second){
    if(first.y < second.y + second.h && first.y > second.y) return 0;
    if(first.x < second.x + second.w && first.x > second.x) return 1;
    if(first.y + first.h > second.y && first.y+first.h < second.y + second.h) return 2;
    if(first.x + first.w > second.x && first.x + first.w < second.x + second.w) return 3;
    return 4;
}
bool Physic::init() {
    return init(std::make_unique<Vector2i>(Vector2i{1, 2}),
        std::make_unique<SDL_Rect>(SDL_Rect{0, 0, 1, 1}), 
        std::make_unique<Vector2f>(Vector2f{1, 1}), 0);
}
bool Physic::init(Vector2iPtr pos_, RectPtr coll_, Vector2fPtr dir_, float force_) {
    GameObject::init(std::move(pos_));
    coll = std::move(coll_);
    setDir(std::move(dir_));
    setForce(force_);
    return true;
}   
void Physic::update (int collision) {
    if(collision == 2){
        force = 0;
        *dir = Vector2f::Zero;
    }
    force += GRAVITY_FORCE;
    *dir += GRAVITY_DIR;
    dir->normalize();

    Vector2f posDif = *dir * force;
    *pos += Vector2i {(int)posDif.x, (int)posDif.y};
}
void Physic::print(){
    std::cout << "collider: " << coll->x << ' ' << coll->y << ' ' << coll->w << " " << coll->h << "\n"
        << "direction: " << dir->x << " " << dir->y << '\n'
        << "force: " << force << "\n";
}