#include "alien.h"

Alien::Alien(Vector2 position) : GameObject(position)
{
    size = Vector2{ alien_size, alien_size };
}