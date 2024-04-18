#include"Object.h"
#include"Textures.h"
GameObject::GameObject(const char* link, int x, int y)
{

    objTex = TextureManage::LoadTexture(link);//load object's image
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
    SDL_RenderCopy(Game::renderer,objTex, NULL, &destRect);
}
