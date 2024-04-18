#include"Collision.h"
#include"SDL.h"
bool Collision::AABB(const SDL_Rect &A, const SDL_Rect &B)
{
    return SDL_HasIntersection(&A,&B);
}
