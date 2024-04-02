#pragma once

#include "raylib.h"

class GameObject
{
public:

    GameObject(Vector2 position = {}, Vector2 size = {});
    virtual ~GameObject() = default;

    virtual void update() {}
    void draw() const;

public:

    Vector2 position{};
    Vector2 size{};

    // TODO: Stocker ici la texture du gameobject

};