#include "projectile.h"

Projectile::Projectile(Vector2 position, Vector2 direction)
    : GameObject(position, Vector2{ projectile_size, projectile_size })
    , direction(direction)
{

}

void Projectile::update()
{
    position = Vector2Multiply
}