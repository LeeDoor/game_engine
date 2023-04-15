#include "go_builder.hpp"
#include "iostream"

GameObjectShar GameObjectBuilder::getValue() {
    return value;
}

GameObjectBuilder* GameObjectBuilder::reset(Vector2i pos_) {
    value = std::make_shared<GameObject>();
    value->init(pos_);
    return this;
}
GameObjectBuilder* GameObjectBuilder::buildDrawable(Vector2i size_, SDL_Renderer *ren_, const char *pathToImage_) {
    value->addComponent<Drawable>().first 
            ->init(value, size_, ren_, pathToImage_);
    return this;
}

GameObjectBuilder* GameObjectBuilder::buildPhysic(Vector2i size_) {
    value->addComponent<Physic>().first
        ->init(value, size_, Vector2f{1, -1}, 10);
    return this;
}   
