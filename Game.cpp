#include"Game.h"
#include"Textures.h"

#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"
#include "Collision.h"
#include "Gravity.h"

//init elements

SDL_Renderer* Game::renderer = nullptr ;
Map* map;
Manager manager;

SDL_Event Game::event;

std::vector <ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& botBorder(manager.addEntity());
auto& leftBorder(manager.addEntity());
auto& topBorder(manager.addEntity());
auto& rightBorder(manager.addEntity());
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

    player.addComponent<TransformComponent>(50,50,32,32,1);
    player.addComponent<SpriteComponent>("mainchar.png");
    player.addComponent<KeyboardHandling>();
    player.addComponent<ColliderComponent>("player");
    player.addComponent<Gravity>(0,1);

    botBorder.addComponent<TransformComponent>(0,gHeight-16,16,gWidth,1);
    botBorder.addComponent<SpriteComponent>("dirt.png");
    botBorder.addComponent<ColliderComponent>("botBorder");

    leftBorder.addComponent<TransformComponent>(0,0, gHeight, 16, 1);
    leftBorder.addComponent<SpriteComponent>("dirt.png");
    leftBorder.addComponent<ColliderComponent>("lBorder");


    topBorder.addComponent<TransformComponent>(0,0,16,gWidth,1);
    topBorder.addComponent<SpriteComponent>("dirt.png");
    topBorder.addComponent<ColliderComponent>("lBorder");
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

	if (  Collision::AABB(player.getComponent<ColliderComponent>().collider, botBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider,leftBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider)) {
		player.getComponent<TransformComponent>().position = playerPos;
		std::cout << "Collision!" << std::endl;
	}
}
void Game::render()
{
    SDL_RenderClear(renderer);
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
void Game::addTile(int id, int x, int y)
{
        auto& tile(manager.addEntity());
        tile.addComponent<TileComponent>(x, y, 32, 32, id);
}
