#include"Game.h"
#include"Textures.h"
#include "Object.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

//init elements
GameObject* player;
SDL_Renderer* Game::renderer = nullptr ;
Map* map;

Manager manager;
auto& newPlayer(manager.addEntity());



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
    player = new GameObject("mainchar.png", 0, 0);//create player
    map = new Map();//create map

    newPlayer.addComponent<PositionComponent>();


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
        manager.update();
        std::cout << newPlayer.getComponent<PositionComponent>().x()<< "," << newPlayer.getComponent<PositionComponent>().y()<< std::endl;

}
void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
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
