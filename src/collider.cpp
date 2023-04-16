#include "collider.hpp"

void Collider::init(GameObjectShar go_, Vector2f size_) {
    Component::init(go_);
    size = size_;
}

void Collider::draw(SDL_Renderer* ren) {
    SDL_SetRenderDrawColor(ren, 38, 255, 74, 255);
    SDL_RenderDrawRect(ren, getRect());
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

void Collider::collideFrom(Direction side, int depth) {
    auto rigid = go.lock()->getComponent<Rigidbody>();
    if(rigid == nullptr_t()) return;
    //std::cout << side << "\n";

    Vector2f sideV = Vector2f::STD[side];
    go.lock()->pos = go.lock()->getPos() + sideV * -1;

    Vector2f startD = rigid->getDir();
    //for x
    if(sideV.x != 0) {
        startD.x = -startD.x;
    }
    else {
        startD.y = -startD.y;
    }
    // fixes bouncing at 0.00-0001 force
    if(rigid->getForce() < 1.0f)
        rigid->setForce(0);
    else
        rigid->setForce(rigid->getForce() * rigid->getElasticity());
    rigid->setDir(startD);
}
SDL_Rect* Collider::getRect() {
    Vector2f pos = go.lock()->getPos();
    return new SDL_Rect {(int)pos.x, (int)pos.y, (int)size.x, (int)size.y};
}