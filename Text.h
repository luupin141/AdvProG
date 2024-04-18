#ifndef Text_h
#define Text_h

#include"SDL_ttf.h"
#include"SDL.h"
#include"string"

class Text {
public:
    Text(const std::string& text, const std::string& fontPath, int fontSize, SDL_Color color);
    ~Text();

    void render(SDL_Renderer* renderer, int x, int y);

private:
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect destRect;
};

#endif // Text_h
