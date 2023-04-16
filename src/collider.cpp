#include "collider.hpp"

void Collider::init(GameObjectShar go_, Vector2f size_) {
    Component::init(go_);
    size = size_;
}

void Collider::draw(SDL_Renderer* ren) {
    Vector2f pos = go.lock()->getPos();
    SDL_SetRenderDrawColor(ren, 38, 255, 74, 255);
    SDL_RenderDrawRect(ren, new SDL_Rect{(int)pos.x, (int)pos.y, (int)size.x, (int)size.y});
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}