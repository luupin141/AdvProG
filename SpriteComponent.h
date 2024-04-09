#ifndef SpriteComponent_h
#define SpriteComponent_h
#include"Components.h"
#include "Textures.h"
#include"SDL.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *trans;
    SDL_Texture *tex;
    SDL_Rect srcR, destR;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);
    }
    ~SpriteComponent()
    {
        SDL_DestroyTexture(tex);
    }
    void setTex(const char* path)
    {
        tex = TextureManage::LoadTexture(path);
    }

    void init() override
    {
        trans = &entity->getComponent<TransformComponent>();
        srcR.x = srcR.y = 0;
        srcR.w = trans->width;
        srcR.h = trans->height;

    }
    void update() override
    {
        destR.x = trans->position.x;
        destR.y = trans->position.y;
        destR.h = trans->height * trans->scale;
        destR.w = trans->width *trans->scale;

    }
    void draw() override
    {
        TextureManage::Draw(tex,srcR,destR);
    }
};

#endif // SpriteComponent_h
