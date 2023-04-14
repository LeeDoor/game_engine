#include "go_director.hpp"

GameObjectDirector::GameObjectDirector() {
    builder = std::make_unique<GameObjectBuilder>();
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_) {
    builder->reset(std::make_unique<Vector2i>(Vector2i{100, 100}))
        ->buildDrawable(std::make_unique<Vector2i>(Vector2i{20, 50}), ren_, "res/smile.bmp")
        ->getValue();
}