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
        scene->destroyGameObject(this);
    }

    Rectangle projectileRect{ position.x, position.y, size.x, size.y };
    for (GameObject* game_object : scene->getGameObjects())
    {
        if (game_object == this)
            continue;

        Rectangle objectRect{ game_object->position.x, game_object->position.y, game_object->size.x, game_object->size.y };
        if (CheckCollisionRecs(projectileRect, objectRect))
        {
            game_object->onHitByProjectile();
            scene->destroyGameObject(this);
            break;
        }
    }
}