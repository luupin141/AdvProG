#ifndef SpriteComponent_h
#define SpriteComponent_h
#include"Components.h"
#include"Anima.h"
#include "Textures.h"
#include"SDL.h"
#include "map"
class SpriteComponent : public Component
{
private:
    TransformComponent *trans;

    SDL_Rect srcR, destR;
    bool animated = 0;
    int frames = 0;
    int speed = 100;

public:
    SDL_Texture *tex;
    int animaIndex = 0;

    std::map<const char *, Anima> animations;

    SDL_RendererFlip spriteflip = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);
    }
     SpriteComponent(const char* path, bool isAnimated)
    {
        animated = isAnimated;

        Anima idle = Anima(0,6,100);
        Anima walk = Anima(1,6,100);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);

        Play("Idle");

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


        if(animated) srcR.x = srcR.w * (int)((SDL_GetTicks()/speed)%frames);

        srcR.y = animaIndex * trans->height;
        destR.x = trans->position.x;
        destR.y = trans->position.y;
        destR.h = trans->height * trans->scale;
        destR.w = trans->width *trans->scale;

    }
    void draw() override
    {
        TextureManage::Draw(tex,srcR,destR,spriteflip);
    }
    void Play(const char* animaName)
    {
        frames = animations[animaName].frames;
        animaIndex = animations[animaName].index;
        speed = animations[animaName].speed;
    }
};

#endif // SpriteComponent_h
