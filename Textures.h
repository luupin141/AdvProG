#ifndef Textures_h
#define Textures_h

#include"Game.h"

class TextureManage{
public:
    static SDL_Texture* LoadTexture(const char* png, SDL_Renderer* ren);
};

#endif // Textures_h



