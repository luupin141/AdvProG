#include"Game.h"
#include"Textures.h"

#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"
#include "Collision.h"

//init elements

SDL_Renderer* Game::renderer = nullptr ;
Map* map;
Manager manager;

SDL_Event Game::event;

std::vector <ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& obstacle(manager.addEntity());
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());
auto& tile3(manager.addEntity());

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

    tile0.addComponent<TileComponent>(200,200,32,32,0);
    tile1.addComponent<TileComponent>(250,200,32,32,0);
    tile2.addComponent<TileComponent>(250,250,32,32,0);



    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("mainchar.png");
    player.addComponent<KeyboardHandling>();
    player.addComponent<ColliderComponent>("player");

    obstacle.addComponent<TransformComponent>(300.0f,300.0f, 300, 20, 1);
    obstacle.addComponent<SpriteComponent>("dirt.png");
    obstacle.addComponent<ColliderComponent>("obstacle");

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
void Game::update() {
	Vector2D playerPos = player.getComponent<TransformComponent>().position;
	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, obstacle.getComponent<ColliderComponent>().collider)) {
		player.getComponent<TransformComponent>().position = playerPos;
		std::cout << "Collision!" << std::endl;
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
