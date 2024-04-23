#ifndef AutoComponent_h
#define AutpComponent_h

#include "Components.h"
#include "Vector2D.h"

class AutoComponent : public Component
{
public:
    int dir = 1;
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
        trans->position.y += dir * Auto.y;
        trans->position.x += dir * Auto.x;
    }


};

#endif // AutoComponent_h
