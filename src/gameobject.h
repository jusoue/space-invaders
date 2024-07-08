#pragma once

#include "raylib.h"

class SpaceInvaders;

class GameObject
{
public:

    GameObject(Vector2 position = {}, Vector2 size = {}, const char* texture_path = "");
    virtual ~GameObject() = default;

    virtual void update() {}
    void draw() const;
    bool isOutOfBounds() const;
    virtual void onHitByProjectile() {}

public:

    Vector2 position{};
    Vector2 size{};
    SpaceInvaders* scene = nullptr;

protected:

    Texture2D texture;
    
};