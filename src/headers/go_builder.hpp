#pragma once
#include "game_object.hpp"

//builder class for game object class
//see more about builder pattern here: https://github.com/RefactoringGuru/design-patterns-cpp/blob/main/src/Builder/Conceptual/main.cc
class GameObjectBuilder {
private:
    GameObjectShar value; // builded value

public:
    GameObjectShar getValue(); // returns value

    GameObjectBuilder* reset(Vector2f pos_); // resets value
    // builds SpriteRenderer component for value
    GameObjectBuilder* buildSpriteRenderer(Vector2f size_, SDL_Renderer *ren_, const char *pathToImage_);
    // builds Rigidbody component for value
    GameObjectBuilder* buildRigidbody(Vector2f dir_ = Vector2f::STD[Direction::Up], float force_ = 0, float elasticity_ = 1);
    // builds Collider component
    GameObjectBuilder* buildCollider(Vector2f size_);

    /*
        keep adding other build functions for other components
    */
};

typedef std::shared_ptr<GameObjectBuilder> GameObjectBuilderShar;
typedef std::unique_ptr<GameObjectBuilder> GameObjectBuilderPtr;