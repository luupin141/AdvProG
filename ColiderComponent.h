#ifndef ColliderComponent_h
#define ColliderComponent_h

#include "string"
#include "SDL.h"
#include "Components.h"
#include "vector"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* trans;

    ColliderComponent(std::string t)
    {
        tag = t;
    }

    void init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        trans = &entity ->getComponent<TransformComponent>();
        Game::colliders.push_back(this);

    }

    void update() override
    {
        collider.x = trans->position.x;
        collider.y = trans->position.y;
        collider.w = trans->width *trans->scale;
        collider.h = trans->height *trans->scale;
    }

};

#endif // ColiderComponent_h
