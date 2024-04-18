#include"Text.h"
#include"Game.h"
Text::Text(const std::string& text, const std::string& fontPath, int fontSize, SDL_Color color)
{
    font = TTF_OpenFont(fontPath.c_str(),fontSize);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &destRect.w, &destRect.h);
    destRect.x = 0;
    destRect.y = 0;
}
Text::~Text()
{
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}
void Text::render(SDL_Renderer* renderer, int x, int y)
{

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
