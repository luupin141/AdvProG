#include "Textures.h"

SDL_Texture* TextureManage::LoadTexture(const char* pngName,SDL_Renderer* renderer)
{
    SDL_Surface* tmpSur = IMG_Load(pngName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,tmpSur);
    SDL_FreeSurface(tmpSur);
    return texture;
}
