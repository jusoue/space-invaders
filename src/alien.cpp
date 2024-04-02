#include "alien.h"

#include "space_invaders.h"

Alien::Alien(Vector2 position) : GameObject(position)
{
    size = Vector2{ alien_size, alien_size };
}

void Alien::onHitByProjectile()
{
    scene->destroyGameObject(this);
}