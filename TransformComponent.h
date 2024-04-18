#ifndef TransformComponent_h
#define TransformComponent_h

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{

public:
    Vector2D position;
    Vector2D velocity;

    int height =32 ;
    int width =32 ;
    int scale = 1;
    int gravity = 64;
    int pace = 2;

    TransformComponent()
    {
        position.Zero();
    }
    TransformComponent(int sc){
        position.Zero();
        scale = sc ;
    }
    TransformComponent(double x, double y, int h, int w, int sc)
    {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override
    {
        velocity.Zero();
    }

    void update() override
    {
        position.x += velocity.x * pace;
        position.y += velocity.y * pace;
    }


};


#endif
