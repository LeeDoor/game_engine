#pragma once
#include "go_builder.hpp"

// director for GameObjectBuilder class
class GameObjectDirector {
private:
    GameObjectBuilderPtr builder; // given builder
    std::vector<DrawableShar>* toDraw;
    std::vector<GameObjectShar>* objects;
    std::vector<ColliderShar>* colliders;
public:
    void init(  std::vector<DrawableShar>* toDraw,
                std::vector<GameObjectShar>* objects,
                std::vector<ColliderShar>* colliders);

    GameObjectShar getObject(); // returns builded object from builder
    void buildPlayer(SDL_Renderer *ren_, Vector2f pos_); // builds player object
    void buildWall(SDL_Renderer *ren_, Vector2f pos_, Vector2f size_); // builds static wall object

    /*
        keep adding new functions for other objects like enemie1 enemie2 wall1 wall2 etc.
    */
};