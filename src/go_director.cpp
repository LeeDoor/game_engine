#include "go_director.hpp"

void GameObjectDirector::init(std::vector<DrawableShar>* toDraw_,
        std::vector<GameObjectShar>* objects_,
        std::vector<ColliderShar>* colliders_) {

    builder = std::make_unique<GameObjectBuilder>();
    
    toDraw = toDraw_;
    objects = objects_;
    colliders = colliders_;
}

GameObjectShar GameObjectDirector::getObject() {
    return builder->getValue();
}

void GameObjectDirector::buildPlayer(SDL_Renderer *ren_, Vector2f pos_) {
    auto player = builder->reset(pos_)
        ->buildSpriteRenderer(Vector2f{20, 50}, ren_, "res/smile.bmp")
        ->buildRigidbody(Vector2f::STD[Direction::Up], 5, 5)
        ->buildCollider(Vector2f{20, 40})
        ->getValue();

    toDraw->push_back(player->getComponent<SpriteRender>());
    toDraw->push_back(player->getComponent<Collider>());
    colliders->push_back(player->getComponent<Collider>());
    objects->push_back(player);
}

        
void GameObjectDirector::buildWall(SDL_Renderer *ren_, Vector2f pos_, Vector2f size_) {
    auto wall = builder->reset(pos_)
            ->buildCollider(size_)
            ->getValue();
    
    toDraw->push_back(wall->getComponent<Collider>());
    colliders->push_back(wall->getComponent<Collider>());
    objects->push_back(wall);
}