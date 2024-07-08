#include "alien_grid.h"

#include "alien.h"
#include "space_invaders.h"
#include "raymath.h"

#include <iostream>

AlienGrid::AlienGrid(SpaceInvaders& game)
{
    int nb_aliens_x = 10;
    int nb_aliens_y = 2;
    for (int x = 0; x < nb_aliens_x; x++)
    {
        for (int y = 0; y < nb_aliens_y; y++)
        {
            Vector2 alien_pos{ 
                float(x) * Alien::alien_size * 2.0f, 
                float(y) * Alien::alien_size * 2.0f };

            Alien* alien = new Alien(alien_pos, this);
            game.addGameObject(alien);
            aliens.push_back(alien);
        }
    }

    width =  (nb_aliens_x - 1) * Alien::alien_size * 2.0f + Alien::alien_size;
    height = (nb_aliens_y - 1) * Alien::alien_size * 2.0f + Alien::alien_size;
}

void AlienGrid::update()
{
    switch (state) 
    {
    case MovementState::RIGHT:
        move(1, 0);
        if (coords.x >= GetRenderWidth() - width)
            state = MovementState::DOWN;
        break;
    case MovementState::LEFT:
        move(-1, 0);
        if (coords.x <= 0.0f)
            state = MovementState::DOWN;
        break;
    case MovementState::DOWN:
        move(0, 1);
        left_to_go_down -= 0.1f;
        if (left_to_go_down <= 0.0f)
        {
            state = going_right == true ? MovementState::LEFT : MovementState::RIGHT;
            going_right = !going_right;
            left_to_go_down = 100.0f;
        }
        break;
    }
}

void AlienGrid::move(int direction_x, int direction_y)
{
    Vector2 movement = Vector2{direction_x * GetFrameTime() * 125.0f, 
                               direction_y * GetFrameTime() * 125.0f};
    
    for (auto alien : aliens) 
    {
        alien->position = Vector2Add(alien->position, movement);
    }

    coords = Vector2Add(coords, movement);
}