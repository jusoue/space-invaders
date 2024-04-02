#pragma once

#include "gameobject.h"

class Alien : public GameObject
{
public:

    Alien(Vector2 position);
    ~Alien() override = default;

    void onHitByProjectile() override;

public:

    static constexpr float alien_size = 25.0f;

};