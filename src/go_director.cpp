#include "go_director.hpp"

GameObjectDirector::GameObjectDirector() {
    builder = std::make_unique<GameObjectBuilder>();
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_) {
    builder->reset(Vector2f{100, 1000})
        ->buildSpriteRenderer(Vector2f{20, 50}, ren_, "res/smile.bmp")
        ->buildRigidbody()
        ->buildCollider(Vector2f{20, 40})
        ->getValue();
}