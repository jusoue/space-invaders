#include "alien_grid.h"

#include "alien.h"
#include "space_invaders.h"

AlienGrid::AlienGrid(SpaceInvaders& game)
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            Vector2 alien_pos{ 
                float(x) * Alien::alien_size * 2.0f, 
                float(y) * Alien::alien_size * 2.0f };

            game.add_gameobject(new Alien(alien_pos));
        }
    }
}