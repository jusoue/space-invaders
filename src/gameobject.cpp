#include "gameobject.h"

GameObject::GameObject(Vector2 position, Vector2 size)
    : position(position)
    , size(size)
{}

void GameObject::draw() const
{
    // TODO: Dessiner la texture à la place d'un rect
    DrawRectangleV(position, size, BLACK);
}
