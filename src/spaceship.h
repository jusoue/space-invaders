#pragma once

#include "gameobject.h"

class Spaceship : public GameObject
{
public:

    Spaceship();
    ~Spaceship() override = default;

    void update() override;

private:

    static constexpr float speed = 200.0f;
    static constexpr float ship_size = 50.0f;

};