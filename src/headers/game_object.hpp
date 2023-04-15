#pragma once
#include "vector2f.hpp"
#include <memory>
#include <vector>
#include "components.hpp"

class GameObject {
protected:
    Vector2f pos;
    std::vector<ComponentShar> components;

public:
    bool init(Vector2f pos_);

    //returns shared pointer to position
    Vector2f getPos();

    // gets needed component from vector 
    template<typename T>
    std::shared_ptr<T> getComponent(){
        for(ComponentShar com : components) 
            if(std::dynamic_pointer_cast<T>(com)) 
                return std::dynamic_pointer_cast<T>(com);
        
        return std::nullptr_t();
    }
    
    // adds T component. returns a pair where first is a link to added/existing component
    // and bool. true if element added and false if element already existed before
    template<typename T>
    std::pair<std::shared_ptr<T>, bool> addComponent(){
        std::shared_ptr<T> comp = getComponent<T>();
        if(comp != std::nullptr_t()) {
            return std::make_pair(comp, false);
        }

        std::shared_ptr<T> newcomp = std::make_shared<T>();
        components.push_back(newcomp);
        return make_pair(newcomp, true);
    }


    //updates data according to all components
    void update();

    friend class Component;
    friend class Physic;
};

typedef std::shared_ptr<GameObject> GameObjectShar;
typedef std::weak_ptr<GameObject> GameObjectWeak;
typedef std::unique_ptr<GameObject> GameObjectPtr;