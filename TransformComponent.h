#ifndef TransformComponent_h
#define TransformComponent_h

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{

public:
    Vector2D position;
    Vector2D velocity;

    int pace = 2;

    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(double x, double y)
    {
        position.x = x;
        position.y = y;
    }

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * pace;
        position.y += velocity.y * pace;
    }


};


#endif
