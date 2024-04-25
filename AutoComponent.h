#ifndef AutoComponent_h
#define AutpComponent_h

#include "Components.h"
#include "Vector2D.h"

class AutoComponent : public Component
{
public:
    int dirX = 1;
    int dirY = 1;
    Vector2D Auto;
    TransformComponent *trans;

    AutoComponent()
    {
        Auto.Zero();
    }

    AutoComponent(double x, double y)
    {
        Auto.x = x;
        Auto.y = y;
    }
    void init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        trans = &entity->getComponent<TransformComponent>();

    }

    void update() override
    {
        trans->position.y += dirY * Auto.y;
        trans->position.x += dirX * Auto.x;
    }


};

#endif // AutoComponent_h
