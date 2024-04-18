#include"Game.h"
#include"Text.h"
#include"Textures.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"
#include "Collision.h"
#include "Gravity.h"
#include "iostream"
#include "vector"
#include"string"
//init elements
int mx;
int my;

Mix_Chunk *menuMix = NULL;
Mix_Chunk *gameMix = NULL;
bool gameStart = 0;



SDL_Renderer* Game::renderer = nullptr ;

Manager manager;
Manager polyglyph;

SDL_Event Game::event;

std::vector <ColliderComponent*> Game::colliders;


auto& background(manager.addEntity());
auto& botBorder(manager.addEntity());
auto& leftBorder(manager.addEntity());
auto& topBorder(manager.addEntity());
auto& spring(manager.addEntity());
auto& grass1(manager.addEntity());
auto& grass2(manager.addEntity());
auto& grass3(manager.addEntity());
auto& grass4(manager.addEntity());
auto& grass5(manager.addEntity());
auto& grass6(manager.addEntity());
auto& grass7(manager.addEntity());
auto& grass8(manager.addEntity());
auto& grass9(manager.addEntity());
auto& grass10(manager.addEntity());
auto& rock1(manager.addEntity());
auto& rock2(manager.addEntity());
auto& rock3(manager.addEntity());
auto& rock4(manager.addEntity());
auto& rock5(manager.addEntity());
auto& pwup(manager.addEntity());
auto& player(manager.addEntity());

auto& menu(manager.addEntity());
auto& menu2(manager.addEntity());

auto& hint1(polyglyph.addEntity());
auto& hint(polyglyph.addEntity());

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int width, int height, bool fullscreen)
{

    int x1,y1;
    x1= rand()%1280+1;
    y1= rand()%640+1;

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
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        isRunning = true;
        menuMix = Mix_LoadWAV("Mixer/menu.wav");
        gameMix = Mix_LoadWAV("Mixer/game.wav");

    }
    else isRunning = false;


    menu.addComponent<TransformComponent>(0,0,gHeight,gWidth,1);
    menu.addComponent<SpriteComponent>("GUI//menu.png");

    background.addComponent<TransformComponent>(0, 0, gHeight, gWidth,1);
    background.addComponent<SpriteComponent>("GUI//background.png");


    player.addComponent<TransformComponent>(0,320,64,32,1);
    player.addComponent<SpriteComponent>("GUI//player.png",1);
    player.addComponent<KeyboardHandling>();
    player.addComponent<ColliderComponent>("player");

    botBorder.addComponent<TransformComponent>(0,gHeight-16,16,gWidth,1);
    botBorder.addComponent<ColliderComponent>("botBorder");

    leftBorder.addComponent<TransformComponent>(0,0, gHeight, 16, 1);
    leftBorder.addComponent<ColliderComponent>("lBorder");




    topBorder.addComponent<TransformComponent>(0,0,0,gWidth,1);
    topBorder.addComponent<ColliderComponent>("lBorder");

    grass1.addComponent<TransformComponent>(14,0,272-16,66,1);
    grass1.addComponent<ColliderComponent>("grass1");

    grass2.addComponent<TransformComponent>(78,0,272-64-16,66*2,1);
    grass2.addComponent<ColliderComponent>("grass2");

    grass3.addComponent<TransformComponent>(206,0,272-64*2-16,64,1);
    grass3.addComponent<ColliderComponent>("grass3");

    grass4.addComponent<TransformComponent>(206+64,0,272-64*3-16,64,1);
    grass4.addComponent<ColliderComponent>("grass4");

    grass5.addComponent<TransformComponent>(206+64,256+16,64-16*2,64*3,1);
    grass5.addComponent<ColliderComponent>("grass5");

    grass6.addComponent<TransformComponent>(206+64*2,256+16-64,64-16*2,64*6,1);
    grass6.addComponent<ColliderComponent>("grass6");

    grass7.addComponent<TransformComponent>(206+64*3,256+16-64*2,64-16*2,64*2,1);
    grass7.addComponent<ColliderComponent>("grass7");

    grass8.addComponent<TransformComponent>(594,147,64-16,64,1);
    grass8.addComponent<ColliderComponent>("grass8");

    grass9.addComponent<TransformComponent>(656,16,64*3-16,64,1);
    grass9.addComponent<ColliderComponent>("grass9");

    grass10.addComponent<TransformComponent>(716,16,112-16,64,1);
    grass10.addComponent<ColliderComponent>("grass10");

    rock1.addComponent<TransformComponent>(852,147,50-16,64,1);
    rock1.addComponent<ColliderComponent>("rock1");

    rock2.addComponent<TransformComponent>(852+66,147,120-16,64,1);
    rock2.addComponent<ColliderComponent>("rock2");

    rock3.addComponent<TransformComponent>(852+64*2+4,147,372-16,54,1);
    rock3.addComponent<ColliderComponent>("rock3");

    rock4.addComponent<TransformComponent>(852+64,150+64*4,64-16,64,1);
    rock4.addComponent<ColliderComponent>("rock4");

    rock5.addComponent<TransformComponent>(722,16+64*7+4,52-16,64*4-8,1);
    rock5.addComponent<ColliderComponent>("rock5");

    hint1.addComponent<TransformComponent>(852,147,50-16,64,1);
    hint1.addComponent<SpriteComponent>();
}
void Game::handleEvent()
{

    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mx = event.motion.x;
            my = event.motion.y;
            if(mx>=522&&mx<=757&&my>=395&&my<=450){
                menu.getComponent<SpriteComponent>().Free();
                gameStart = 1;
            }
            else if (mx>=568&&mx<=717&&my>=495&&my<=528)
                menu.getComponent<SpriteComponent>().setTex("GUI/guide.png");
            break;

    }
}

void Game::update() {

    //play mix
    if(!gameStart){Mix_PlayChannel(-1,menuMix,-1);}
    else if(gameStart) {
        Mix_HaltChannel(Mix_PlayChannel(-1,menuMix,-1));
        Mix_PlayChannel(-1,gameMix,-1);

    }

	Vector2D playerPos = player.getComponent<TransformComponent>().position ;
	manager.refresh();
	manager.update();
	//std::cout<<mx<<" "<<my<<std::endl;
	if (playerPos.x>1280)
    {
        int tmp = playerPos.x-1280;
        background.getComponent<SpriteComponent>().setxrect(tmp);
        background.getComponent<SpriteComponent>().destR.w-tmp;

    }
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,rock1.getComponent<ColliderComponent>().collider))
    {
        hint1.getComponent<SpriteComponent>().setTex("GUI/map.png");
    }
    if (playerPos.x<-16 || playerPos.y<-16){
        isRunning = false;}
	if (  Collision::AABB(player.getComponent<ColliderComponent>().collider, botBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, topBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass1.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass2.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass3.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass4.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass5.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass6.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass7.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass8.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass9.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, grass10.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock1.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock2.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock3.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock4.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock5.getComponent<ColliderComponent>().collider)){
            player.getComponent<TransformComponent>().position = playerPos;
            std::cout << "Collision!" << std::endl;
	}

}
void Game::render()
{
    SDL_RenderClear(renderer);polyglyph.draw();
    manager.draw();

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    Mix_FreeChunk(gameMix);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
