#ifndef Tactic_h
#define Tactic_h

#include"Components.h"
#include"Vector2D.h"

class Tactic : public Component
{
    public:
    Vector2D tactic;
    TransformComponent *trans;
    int ttMode = 0;
    int distance;
    Vector2D pos = trans->position;
    Tactic()
    {
        tactic.Zero();
    }

    Tactic(double x, double y, int mode)
    {
        tactic.x = x;
        tactic.y = y;
        ttMode = mode;
    }
    Tactic(double x, double y, int mode, int range)
    {
        tactic.x = x;
        tactic.y = y;
        ttMode = mode;
        distance = range;
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
        if(ttMode==1)
        {
        trans->velocity.y += tactic.y;
        SDL_Delay(10);
        }
        if(ttMode==2)
        {
            int limit = trans->position.x + distance;
            if(trans->position.x<limit) {trans->velocity.x+=tactic.x;}
            else if (trans->position.x==limit) trans->position = pos;
        }
    }
};
#endif // Gravity_h
