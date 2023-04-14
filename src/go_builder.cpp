#include "go_builder.hpp"
#include "iostream"

GameObjectShar GameObjectBuilder::getValue() {
    auto t = value;
    value = nullptr;
    return t;
}

GameObjectBuilder* GameObjectBuilder::reset(Vector2iPtr pos_) {
    if(pos_ == nullptr){ 
        std::cout << "bababa";
        return this;
    }
    value = std::make_shared<GameObject>();
    if(value == nullptr){
        std::cout << "bububu";
        return this;
    }
    value->init(std::move(pos_));
    return this;
}
GameObjectBuilder* GameObjectBuilder::buildDrawable(Vector2iPtr size_, SDL_Renderer *ren_, const char *pathToImage_) {
    if(size_ == nullptr || ren_ == nullptr) {
        std::cout << "bebebe";
        return this;
    }
    value->addComponent<Drawable>().first 
            ->init(value, std::move(size_), ren_, pathToImage_);
    return this;
}