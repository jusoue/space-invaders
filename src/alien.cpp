#include "alien.h"

#include "alien_grid.h"
#include "space_invaders.h"

Alien::Alien(Vector2 position, AlienGrid* grid) : GameObject(position), grid(grid)
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