#include"Game.h"
#include"Textures.h"

#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"

//init elements

SDL_Renderer* Game::renderer = nullptr ;
Map* map;
Manager manager;
auto& player(manager.addEntity());
SDL_Event Game::event;


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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
            std::cout<<"renderercreated"<<std::endl;
        }
        isRunning = true;

    }
    else isRunning = false;

    map = new Map();//create map

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("mainchar.png");
    player.addComponent<KeyboardHandling>();

}
void Game::handleEvent()
{

    SDL_PollEvent(&event);
    switch(event.type)
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
        manager.refresh();
        manager.update();
        if(player.getComponent<TransformComponent>().position.x>100)
        {
            player.getComponent<SpriteComponent>().setTex("mainchar2.png");
        }


}
void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
