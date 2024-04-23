#include "Text.h"

Text::Text(SDL_Renderer* renderer, const std::string& fontPath, int fontSize)
    : renderer(renderer), font(nullptr), texture(nullptr) {
    loadFont(fontPath, fontSize);
}

Text::~Text() {
    if (font) {
        TTF_CloseFont(font);
    }
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Text::loadFont(const std::string& fontPath, int fontSize) {
    font = TTF_OpenFont(fontPath.c_str(), fontSize);

}

void Text::setText(const std::string& text, SDL_Color color) {
    if (font) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
        if (surface) {
            if (texture) {
                SDL_DestroyTexture(texture);
            }
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
        }
    }
}

void Text::render(int x, int y) {
    if (texture) {
        SDL_Rect dstRect = {x, y, 0, 0};
        SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
        SDL_RenderCopy(Game::renderer, texture, NULL, &dstRect);
    }
}

