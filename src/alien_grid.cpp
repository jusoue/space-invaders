#include "alien_grid.h"

#include "alien.h"
#include "space_invaders.h"
#include "raymath.h"

#include <iostream>

AlienGrid::AlienGrid(SpaceInvaders& game)
{
    int nb_aliens_x = 10;
    int nb_aliens_y = 2;

    // TODO: Créer le bon nombre d'aliens et leur donner des posisions
    //       sous forme de grille. Ajouter les aliens dans le game puis
    //       dans le vecteur "aliens".
    








    width =  (nb_aliens_x - 1) * Alien::alien_size * 2.0f + Alien::alien_size;
    height = (nb_aliens_y - 1) * Alien::alien_size * 2.0f + Alien::alien_size;
}

void AlienGrid::update()
{
    switch (state) 
    {
    case MovementState::RIGHT:
        // TODO: Se déplacer à droite puis, si les aliens arrivent au bout,
        //       aller vers le bas



        break;
    case MovementState::LEFT:
        // TODO: Se déplacer à gauche puis, si les aliens arrivent au bout,
        //       aller vers le bas
        


        break;
    case MovementState::DOWN:
        // TODO: Se déplacer vers le bas
        
        left_to_go_down -= 0.1f;
        if (left_to_go_down <= 0.0f)
        {
            state = going_right == true ? MovementState::LEFT : MovementState::RIGHT;
            going_right = !going_right;
            left_to_go_down = 100.0f;
        }
        break;
    }
}

void AlienGrid::move(int direction_x, int direction_y)
{
    Vector2 movement = Vector2{direction_x * GetFrameTime() * 125.0f, 
                               direction_y * GetFrameTime() * 125.0f};
    
    for (auto alien : aliens) 
    {
        // TODO: Additioner le vecteur de mouvement à la position de l'alien.
        // Indice: Utilisez la fonction Vector2Add()!
        
    }

    // TODO: Additionner le vecteur de mouvement aux coordonnées de la grille
    
}