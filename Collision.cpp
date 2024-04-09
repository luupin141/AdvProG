#include"Collision.h"
#include"ColiderComponent.h"
bool Collision::AABB(const SDL_Rect& A, const SDL_Rect& B)
{
    if(
         A.x + A.w > B.x
       &&A.y + A.h > B.y +4
       &&B.x + B.w > A.x
       &&B.y + B.h > A.y -4
        ) return true;
    return false;
}
bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
    if(AABB(colA.collider,colB.collider))
    {
        std::cout << colA.tag << "x" << colB.tag << std::endl;
        return true;
    }
    else return false;
}
