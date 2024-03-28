#include"Object.h"
#include"Textures.h"
GameObject::GameObject(const char* link, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTex = TextureManage::LoadTexture(link,ren);//load object's image
    xpos = x;
    ypos = y;
}
void GameObject::Update()//update object position and size
{
    xpos++;
    ypos++;


    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 32  ;
    destRect.h = 32 ;
}
void GameObject::Render()//render object position and size
{
    SDL_RenderCopy(renderer,objTex, NULL, &destRect);
}
