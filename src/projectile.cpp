#include "projectile.h"
#include "raymath.h"
#include "space_invaders.h"

Projectile::Projectile(Vector2 position, const char* texture_path, Vector2 direction)
    : GameObject(position, Vector2{ projectile_size, projectile_size }, texture_path)
    , direction(direction)
{
    
}

void Projectile::update()
{
    position = Vector2Add(Vector2Scale(direction, GetFrameTime() * projectile_speed), position);

    // TODO: Si le projectile est endehors des limites, détruire le projectile de la scene
    



    Rectangle projectileRect{ position.x, position.y, size.x, size.y };
    for (GameObject* game_object : scene->getGameObjects())
    {
        if (game_object == this)
            continue;

        Rectangle objectRect{ game_object->position.x, game_object->position.y, game_object->size.x, game_object->size.y };
        // TODO: S'il y a collision entre le projectileRect et l'objectRect, appeler onHitByProjectile de l'objet
        //       puis détruire le projectile de la scene. Indice: Utilisez CheckCollisionRecs()!
        // if ()
        // {
        //     
        //     break; // Permet d'arrêter la for loop après que le projectile a touché une cible
        // }
    }
}