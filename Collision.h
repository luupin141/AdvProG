#ifndef Collision_h
#define Collision_h

#include <SDL.h>

class ColliderComponent;

class Collision
{
public:
	static bool AABB(const SDL_Rect& A, const SDL_Rect& B);

};
#endif // Collision_h
