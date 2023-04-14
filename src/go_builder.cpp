#include "go_builder.hpp"
#include "iostream"

GameObjectShar GameObjectBuilder::getValue() {
    return value;
}

GameObjectBuilder* GameObjectBuilder::reset(Vector2iPtr pos_) {
    value = std::make_shared<GameObject>();
    value->init(std::move(pos_));
    return this;
}
GameObjectBuilder* GameObjectBuilder::buildDrawable(Vector2iPtr size_, SDL_Renderer *ren_, const char *pathToImage_) {
    value->addComponent<Drawable>().first 
            ->init(value, std::move(size_), ren_, pathToImage_);
    return this;
}