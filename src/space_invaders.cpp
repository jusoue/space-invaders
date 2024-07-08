#include "space_invaders.h"

#include "alien_grid.h"
#include "gameobject.h"
#include "spaceship.h"

#include <raymath.h>

SpaceInvaders::SpaceInvaders()
{
    alien_grid = new AlienGrid(*this);

    // Le joueur
    addGameObject(new Spaceship());
}

SpaceInvaders::~SpaceInvaders()
{
    delete alien_grid;

    for (GameObject* game_object : game_objects)
        delete game_object;
}

void SpaceInvaders::update()
{
    if (is_game_over)
        return;

    while(!game_objects_to_add.empty())
    {
        game_objects.emplace(game_objects_to_add.front());
        game_objects_to_add.pop();
    }

    while(!game_objects_to_delete.empty())
    {
        game_objects.erase(game_objects_to_delete.front());
        delete game_objects_to_delete.front();
        game_objects_to_delete.pop();
    }

    for (GameObject* game_object : game_objects)
        game_object->update();

    alien_grid->update();

    checkGameOver();
}

void SpaceInvaders::draw() const
{
    for (const GameObject* game_object : game_objects)
        game_object->draw();

    if (is_game_over)
    {
        drawGameOver();
    }
}

void SpaceInvaders::addGameObject(GameObject* game_object)
{
    game_objects_to_add.push(game_object);
    game_object->scene = this;
}

void SpaceInvaders::destroyGameObject(GameObject* game_object)
{
    game_objects_to_delete.push(game_object);
}

void SpaceInvaders::checkGameOver()
{
    if (alien_grid->coords.y >= (GetRenderHeight() - 50.0f * 2.0f) - alien_grid->height)
    {
        is_game_over = true;
    }

    if (alien_grid->aliens.empty())
    {
        is_game_over = true;
        is_victory = true;
    }
}

void SpaceInvaders::drawGameOver() const
{
    const char* message = is_victory ? "You won!" : "You lost.";
    Vector2 text_size = MeasureTextEx(GetFontDefault(), message, 30, 0);
    DrawText(message, (GetRenderWidth() - text_size.x) / 2, GetRenderHeight() / 2, 30, WHITE);
}