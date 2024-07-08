#include "alien.h"

#include "alien_grid.h"
#include "space_invaders.h"

Alien::Alien(Vector2 position, Vector2 size, const char* texture_path, AlienGrid* grid)
    : GameObject(position, size, texture_path), grid(grid)
{
    size = Vector2{ alien_size, alien_size };
}

void Alien::onHitByProjectile()
{
    scene->destroyGameObject(this);
    for (int i = 0; i < grid->aliens.size(); i++)
    {
        if (grid->aliens[i] == this)
        {
            grid->aliens.erase(grid->aliens.begin() + i);
        }
    }
}