#pragma once
#include "go_builder.hpp"

class GameObjectDirector {
private:
    GameObjectBuilderPtr builder;

public:
    GameObjectDirector();

    GameObjectShar getObject();
    void buildPlayer(SDL_Renderer *ren_);
};