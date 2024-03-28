#include"Game.h"
#include"Textures.h"
#include "Object.h"

GameObject* player;

Game::Game()
{

}
Game::~Game(){}
void Game::init(const char* title, int width, int height, bool fullscreen)
{

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std::cout<<"khoitaothanhcong"<<std::endl;

        window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
        if(window){
            std::cout<<"windowcreated"<<std::endl;
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
            std::cout<<"renderercreated"<<std::endl;
        }
        isRunning = true;

    }
    else isRunning = false;
    player = new GameObject("mainchar.png",renderer, 0, 0);//create player

}
void Game::handleEvent()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}
void Game::update()
{
        player->Update();
}
void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
