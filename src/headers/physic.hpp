#pragma once 
#include <SDL.h>
#include "vector2f.hpp"
#include "game_object.hpp"
#include <memory>
#include <iostream>

typedef std::unique_ptr<SDL_Rect> RectPtr;

class Physic : public GameObject {
private:
protected:
    RectPtr coll; // collider hitbox
    Vector2fPtr dir; // direction of force
    float force; // force value
    
public:
    const float GRAVITY_FORCE = 5;
    const Vector2f GRAVITY_DIR = Vector2f::Down;

    float getForce() {return force;}
    void setForce(float force_) {force = force_;}

    Vector2f* getDir() {return dir.get();}
    void setDir(Vector2fPtr dir_) {
        dir_->normalize();
        dir = std::move(dir_);
    }

    //    0
    //  1 4 3
    //    2
    // returns 0 if collision is upside, 1 if leftside, 2 if downside and 3 if rightside
    static int isCollide(SDL_Rect& first, SDL_Rect& second){
        if(first.y < second.y + second.h && first.y > second.y) return 0;
        if(first.x < second.x + second.w && first.x > second.x) return 1;
        if(first.y + first.h > second.y && first.y+first.h < second.y + second.h) return 2;
        if(first.x + first.w > second.x && first.x + first.w < second.x + second.w) return 3;
        return 4;
    }

    bool init() {
        return init(std::make_unique<Vector2f>(Vector2f{1, 2}),
            std::make_unique<SDL_Rect>(SDL_Rect{0, 0, 1, 1}), 
            std::make_unique<Vector2f>(Vector2f{1, 1}), 0);
    }
    bool init(Vector2fPtr pos_, RectPtr coll_, Vector2fPtr dir_, float force_) {
        GameObject::init(std::move(pos_));
        coll = std::move(coll_);
        setDir(std::move(dir_));
        setForce(force_);
        return true;
    }   
    void update (int collision = 4) {
        if(collision == 2){
            force = 0;
            *dir = Vector2f::Zero;
        }
        force += GRAVITY_FORCE;
        *dir += GRAVITY_DIR;
        dir->normalize();

        *pos += *dir * force;
    }
    void print(){
        std::cout << "collider: " << coll->x << ' ' << coll->y << ' ' << coll->w << " " << coll->h << "\n"
        << "direction: " << dir->x << " " << dir->y << '\n'
        << "force: " << force << "\n";
    }
};