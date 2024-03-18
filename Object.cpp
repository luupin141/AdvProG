#include "Object.h"
#include<iostream>

Object::Object()
{
    _texture = NULL;
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 0;
    _rect.h = 0;
}
Object::~Object()
{
    Free();
}
bool Object::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if(load_surface!=NULL)
    {
        SDL_SetColorKey(load_surface,SDL_TRUE, SDL_MapRGB(load_surface->format,CLK_R,CLK_G,CLK_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if(new_texture!=NULL)
        {
            _rect.w= load_surface->w;
            _rect.h= load_surface->h;
        }

        SDL_FreeSurface(load_surface);

    }
    _texture = new_texture;

    return _texture != NULL;
}
void Object::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad = {_rect.x, _rect.y, _rect.w, _rect.h };

    SDL_RenderCopy(des,_texture,clip, &renderquad);

}
void Object::Free()
{
    SDL_DestroyTexture(_texture);
        _texture = NULL;
        _rect.h = 0;
        _rect.w = 0;

}
