#include "ttf.hpp"

TTF::TTF() {
    if (TTF_Init() < 0) {
        printf("TTF could not initialize! TTF_Error: %s\n", TTF_GetError());
        exit(1);
    }
}

TTF::~TTF() {
    TTF_Quit();
}

bool TTF::loadFont(const std::string& file, int size) {
    font = TTF_OpenFont(file.c_str(), size);
    if (!font) {
        printf("Font could not be loaded! TTF_Error: %s\n", TTF_GetError());
        return false;
    }
    return true;
}

void TTF::renderText(const std::string& text, int x, int y, SDL_Color fg) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fg);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void TTF::setRenderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}
