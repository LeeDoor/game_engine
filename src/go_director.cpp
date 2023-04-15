#include "go_director.hpp"

GameObjectDirector::GameObjectDirector() {
    builder = std::make_unique<GameObjectBuilder>();
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_) {
    builder->reset(Vector2i{100, 100})
        ->buildDrawable(Vector2i{20, 50}, ren_, "res/smile.bmp")
        ->buildPhysic(Vector2i{20, 50})
        ->getValue();
}