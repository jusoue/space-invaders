#include "projectile.h"
#include "raymath.h"
#include "space_invaders.h"

Projectile::Projectile(Vector2 position, Vector2 direction)
    : GameObject(position, Vector2{ projectile_size, projectile_size })
    , direction(direction)
{
    
}

void Projectile::update()
{
    position = Vector2Add(Vector2Scale(direction, GetFrameTime() * projectile_speed), position);

    if (isOutOfBounds())
    {
        scene->destroy_gameobject(this);
    }
}

bool Projectile::isOutOfBounds()
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y > GetScreenHeight() || position.y < 0;
}