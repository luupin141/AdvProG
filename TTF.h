#ifndef TTF_HPP
#define TTF_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TTF {
public:
    TTF();
    ~TTF();
    bool loadFont(const std::string& file, int size);
    void renderText(const std::string& text, int x, int y, SDL_Color fg);
    void setRenderer(SDL_Renderer* renderer);

private:
    TTF_Font* font = NULL;
    SDL_Renderer* renderer = NULL;
};

#endif // TTF_HPP
