#include "space_invaders.h"

#include "alien_grid.h"
#include "gameobject.h"
#include "spaceship.h"

#include <raymath.h>

SpaceInvaders::SpaceInvaders()
{
    alien_grid = new AlienGrid(*this);

    // Le joueur
    add_gameobject(new Spaceship());
}

SpaceInvaders::~SpaceInvaders()
{
    delete alien_grid;

    for (GameObject* game_object : game_objects)
        delete game_object;
}

void SpaceInvaders::update()
{
    for (GameObject* game_object : game_objects)
        game_object->update();
}

void SpaceInvaders::draw() const
{
    for (const GameObject* game_object : game_objects)
        game_object->draw();
}

void SpaceInvaders::add_gameobject(GameObject* game_object)
{
    game_objects.emplace(game_object);
}

void SpaceInvaders::destroy_gameobject(GameObject* game_object)
{
    game_objects.erase(game_object);
    delete game_object;
}