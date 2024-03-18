#ifndef OBJECT_H_
#define OBJECT_H_

#include "Base.h"

class Object{
    public:
        Object();
        ~Object();
        void SetRect(const int& x, const int& y){_rect.x=x,_rect.y=y;}
        SDL_Rect GetRect() {return _rect;}
        SDL_Texture* GetObj(){return _texture;}
        bool LoadImg(std::string path, SDL_Renderer* screen);
        void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
        void Free();

    protected:
        SDL_Texture* _texture;
        SDL_Rect _rect;
};

#endif // OBJECT_H_
