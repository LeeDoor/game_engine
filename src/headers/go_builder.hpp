#pragma once
#include "game_object.hpp"

class GameObjectBuilder {
private:
    GameObjectShar value;

public:
    GameObjectShar getValue();

    GameObjectBuilder* reset(Vector2iPtr pos_);
    GameObjectBuilder* buildDrawable(Vector2iPtr size_, SDL_Renderer *ren_, const char *pathToImage_);
};