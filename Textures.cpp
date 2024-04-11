#include "Textures.h"
#include "Object.h"
SDL_Texture* TextureManage::LoadTexture(const char* pngName)//load image
{
    SDL_Surface* tmpSur = IMG_Load(pngName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tmpSur);
    SDL_FreeSurface(tmpSur);
    return texture;
}
void TextureManage::Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,tex, &src, &dest);
}
