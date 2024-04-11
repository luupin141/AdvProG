#ifndef TileComponent_h
#define TileComponent_h

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *trans;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    char* path;



    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x; tileRect.y = y;
        tileRect.w = w; tileRect.h = h;
        tileID = id;

        switch (tileID)
        {
        case 0:
            path = "dirt.png";
            break;
        case 1:
            path = "grass.png";
            break;
        case 2:
            path = "water.png";
            break;
        case 3:
            path = "sand.png";
            break;
        case 4:
            path = "gate.png";
            break;
        default:
            break;

        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>((double)tileRect.x,(double)tileRect.y,tileRect.w, tileRect.h, 1);
        trans = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }

};

#endif // TileComponent_h
