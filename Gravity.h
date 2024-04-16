#ifndef Gravity_h
#define Gravity_h

#include"Components.h"
#include"Vector2D.h"

class Gravity : public Component
{
    public:
    Vector2D gravity;
    TransformComponent *trans;

    Gravity()
    {
        gravity.Zero();
    }

    Gravity(double x, double y)
    {
        gravity.x = x;
        gravity.y = y;
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
        trans->velocity.y += gravity.y;
        SDL_Delay(10);
    }
};
#endif // Gravity_h
