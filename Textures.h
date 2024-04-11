#ifndef Textures_h
#define Textures_h

#include"Game.h"

class TextureManage{
public:
    static SDL_Texture* LoadTexture(const char* png);
    static void Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest);

};

#endif // Textures_h



