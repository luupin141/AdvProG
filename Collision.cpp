#include"Collision.h"
#include"ColiderComponent.h"
bool Collision::AABB(const SDL_Rect& A, const SDL_Rect& B)
{
    return SDL_HasIntersection(&A,&B);
}
