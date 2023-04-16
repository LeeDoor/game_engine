#include "rigidbody.hpp"
#include "physics.hpp"

float Rigidbody::getForce() { 
    return force; 
}
void Rigidbody::setForce(float force_) { 
    force = force_; 
}

Vector2f Rigidbody::getDir() {
    return dir;
}
void Rigidbody::setDir(Vector2f dir_) {
    dir_.normalize();
    dir = dir_;
}

float Rigidbody::getElasticity() {
    return elasticity;
}

void Rigidbody::setElasticity(float el_) {
    elasticity = std::abs(el_);
}


bool Rigidbody::init(GameObjectShar go_, Vector2f dir_, float force_, float elasticity_) {
    Component::init(go_);
    setDir(dir_);
    setForce(force_);
    setElasticity(elasticity_);
    return true;
}   
void Rigidbody::update () {
    int collision = 4;
    if(collision == 2){
        force = 0;
        dir = Vector2f::STD[Direction::None];
        return;
    }
    Vector2f newPos = dir * force + Physics::GRAVITY_DIR * Physics::GRAVITY_FORCE;
    go.lock()->pos += Vector2f(newPos.x, newPos.y);
    setForce(newPos.len());
    setDir(newPos);
}