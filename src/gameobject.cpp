#include "gameobject.h"

GameObject::GameObject(Vector2 position, Vector2 size, const char* texture_path)
    : position(position)
    , size(size)
{
    texture = LoadTexture(texture_path);
}

void GameObject::draw() const
{
    DrawTexturePro
    (
        texture, 
        {0, 0, 11, 11},
        {position.x, position.y, size.x, size.y},
        {0, 0},
        0.0f,
        WHITE
    );
}

bool GameObject::isOutOfBounds() const
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y > GetScreenHeight() || position.y < 0;
}
