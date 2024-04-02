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
}

void SpaceInvaders::draw() const
{
    for (const GameObject* game_object : game_objects)
        game_object->draw();
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