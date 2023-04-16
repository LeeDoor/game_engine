#include "go_builder.hpp"
#include "iostream"

GameObjectShar GameObjectBuilder::getValue() {
    return value;
}

GameObjectBuilder* GameObjectBuilder::reset(Vector2f pos_) {
    value = std::make_shared<GameObject>();
    value->init(pos_);
    return this;
}
GameObjectBuilder* GameObjectBuilder::buildSpriteRenderer(Vector2f size_, SDL_Renderer *ren_, const char *pathToImage_) {
    value->addComponent<SpriteRender>().first 
            ->init(value, size_, ren_, pathToImage_);
    return this;
}

GameObjectBuilder* GameObjectBuilder::buildRigidbody() {
    value->addComponent<Rigidbody>().first
        ->init(value, Vector2f::STD[Direction::Right], 10);
    return this;
}   


GameObjectBuilder* GameObjectBuilder::buildCollider(Vector2f size_) {
    value->addComponent<Collider>().first
        ->init(value, size_);
    return this;
}
