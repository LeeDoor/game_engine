#include "go_director.hpp"

GameObjectDirector::GameObjectDirector() {
    builder = std::make_unique<GameObjectBuilder>();
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_, Vector2f pos_) {
    builder->reset(pos_)
        ->buildSpriteRenderer(Vector2f{20, 50}, ren_, "res/smile.bmp")
        ->buildRigidbody()
        ->buildCollider(Vector2f{20, 40})
        ->getValue();
}

        
void GameObjectDirector::buildWall(SDL_Renderer *ren_, Vector2f pos_, Vector2f size_) {
    builder->reset(pos_)
            ->buildCollider(size_)
            ->getValue();
}