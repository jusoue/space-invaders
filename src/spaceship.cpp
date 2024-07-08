#include "spaceship.h"
#include "projectile.h"
#include "space_invaders.h"

#include "raylib.h"
#include "raymath.h"

Spaceship::Spaceship(const char* texture_path)
    : GameObject(Vector2{ GetRenderWidth() / 2.0f, GetRenderHeight() - size.y * 2.0f },
                 Vector2{ 50.0f, 50.0f },
                 texture_path)
{
    size = Vector2{ 50.0f, 50.0f };
    position = Vector2{ GetRenderWidth() / 2.0f, GetRenderHeight() - size.y * 2.0f };
}

void Spaceship::update()
{
    int input = int(IsKeyDown(KEY_RIGHT)) - int(IsKeyDown(KEY_LEFT));
    float movement = input * GetFrameTime() * speed;

    position = Vector2Add(position, Vector2{ movement, 0.0f });

    if(IsKeyReleased(KEY_SPACE))
    {
        // TODO: Ce calcul serait pas mal plus simple si les positions représentaient le centre de chaque objet, au lieu 
        //       des top-left. Le GameObject pourrait calculer lui-même le Rectangle utilisé pour les tests de collision.
        Projectile* projectile = new Projectile(Vector2Add(position,
            Vector2{ size.x / 2.0f - Projectile::projectile_size / 2.0f, -Projectile::projectile_size - EPSILON }), "../../res/projectile.png", {0, -1});
        scene->addGameObject(projectile);
    }
}