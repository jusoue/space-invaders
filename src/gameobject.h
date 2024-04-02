#pragma once

#include "raylib.h"

class SpaceInvaders;

class GameObject
{
public:

    GameObject(Vector2 position = {}, Vector2 size = {});
    virtual ~GameObject() = default;

    virtual void update() {}
    void draw() const;
    bool isOutOfBounds() const;
    virtual void onHitByProjectile() {}

public:

    Vector2 position{};
    Vector2 size{};
    SpaceInvaders* scene = nullptr;

    // TODO: Stocker ici la texture du gameobject

};