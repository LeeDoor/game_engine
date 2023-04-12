#pragma once 
#include <memory>

class GameObject;
typedef std::shared_ptr<GameObject> GameObjectShar;
typedef std::weak_ptr<GameObject> GameObjectWeak;
typedef std::unique_ptr<GameObject> GameObjectPtr;

class Component {
protected:
    GameObjectWeak go;
public:
    bool init(GameObjectShar go_);
    virtual void update() = 0;
};

typedef std::unique_ptr<Component> ComponentPtr;
typedef std::shared_ptr<Component> ComponentShar;