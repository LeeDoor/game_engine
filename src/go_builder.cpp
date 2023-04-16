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
GameObjectBuilder* GameObjectBuilder::buildDrawable(Vector2f size_, SDL_Renderer *ren_, const char *pathToImage_) {
    value->addComponent<SpriteRender>().first 
            ->init(value, size_, ren_, pathToImage_);
    return this;
}

GameObjectBuilder* GameObjectBuilder::buildPhysic() {
    value->addComponent<Rigidbody>().first
        ->init(value, Vector2f::Up, 70);
    return this;
}   
