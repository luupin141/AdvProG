#ifndef Object_h
#define Object_h

#include "Game.h"
class GameObject
{
public:
    GameObject(const char* link, int x, int y);
    ~GameObject();

    void Update();
    void Render();
private:
    int xpos, ypos;
    SDL_Texture* objTex;
    SDL_Rect srcRect,destRect;
    //srcRect adjust source image to load into texture
    //destRect adjust texture's position and size on window


};

#endif // Object_h
