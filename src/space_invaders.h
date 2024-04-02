#pragma once

#include <unordered_set>

class AlienGrid;
class GameObject;

class SpaceInvaders
{
public:

    SpaceInvaders();
    ~SpaceInvaders();

    void update();
    void draw() const;

    void add_gameobject(GameObject* game_object);
    void destroy_gameobject(GameObject* game_object);

private:

    AlienGrid* alien_grid;
    std::unordered_set<GameObject*> game_objects{};

};