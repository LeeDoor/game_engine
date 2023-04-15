#include "go_director.hpp"

GameObjectDirector::GameObjectDirector() {
    builder = std::make_unique<GameObjectBuilder>();
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_) {
    builder->reset(Vector2f{100, 100})
        ->buildDrawable(Vector2f{20, 50}, ren_, "res/smile.bmp")
        ->buildPhysic(Vector2f{20, 50})
        ->getValue();
}