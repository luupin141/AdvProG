#ifndef TEXT_H
#define TEXT_H

#include"Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text {
public:
    Text(SDL_Renderer* renderer, const std::string& fontPath, int fontSize);
    ~Text();

    void loadFont(const std::string& fontPath, int fontSize);
    void setText(const std::string& text, SDL_Color color);
    void render(int x, int y);

private:
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};

#endif // TEXT_H
