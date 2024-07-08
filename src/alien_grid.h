#pragma once
#include <vector>
#include "raylib.h"

class SpaceInvaders;
class Alien;

enum class MovementState 
{ 
    RIGHT, LEFT, DOWN
};

class AlienGrid
{
public:

    AlienGrid(SpaceInvaders& game);
    void update();

    std::vector<Alien*> aliens;
    Vector2 coords{0.0f, 0.0f};
    float width = 0.0f;
    float height = 0.0f;
    
private:

    void move(int direction_x, int direction_y);

    MovementState state = MovementState::RIGHT;
    float left_to_go_down = 100.0f;
    bool going_right = true;
};