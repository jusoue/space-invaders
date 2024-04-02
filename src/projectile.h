#pragma once

#include "gameobject.h"

class Projectile : public GameObject
{
public:

    Projectile(Vector2 position, Vector2 direction);

    void update() override;

private:

    static constexpr float projectile_size = 10.0f;
    static constexpr float projectile_speed = 400.0f;

    Vector2 direction{};

};