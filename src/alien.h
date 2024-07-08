#pragma once

#include "gameobject.h"

class AlienGrid;

class Alien : public GameObject
{
public:

    Alien(Vector2 position, Vector2 size, const char* texture_path, AlienGrid* grid);
    ~Alien() override = default;

    void onHitByProjectile() override;

public:

    static constexpr float alien_size = 25.0f;

private:

    AlienGrid* grid = nullptr;

};