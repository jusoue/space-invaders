#pragma once

#include <unordered_set>
#include <queue>

class AlienGrid;
class GameObject;

class SpaceInvaders
{
public:

    SpaceInvaders();
    ~SpaceInvaders();

    void update();
    void draw() const;

    void addGameObject(GameObject* game_object);
    void destroyGameObject(GameObject* game_object);
    
    const std::unordered_set<GameObject*>& getGameObjects() const { return game_objects; }

private:

    AlienGrid* alien_grid;

    // On utilise des queues pour que les objets s'enlèvent dans le bon ordre
    std::unordered_set<GameObject*> game_objects{};
    std::queue<GameObject*> game_objects_to_add;
    std::queue<GameObject*> game_objects_to_delete;

    bool is_game_over = false;
    bool is_victory = false;

    void checkGameOver();
    void drawGameOver() const;

};