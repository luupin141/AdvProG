#include"Game.h"
#include"Text.h"
#include"Textures.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"
#include "Collision.h"
#include "Tactic.h"
#include "Text.h"
#include "iostream"
#include "vector"
#include"string"
//init elements
int mx;
int my;
int HP = 5;
int score = 10000;
Vector2D startPos(16,320);
Text *scoreText = NULL;

//mix init
Mix_Chunk *menuMix = NULL;
Mix_Chunk *gameMix = NULL;
Mix_Chunk *trueMix = NULL;
Mix_Chunk *falseMix = NULL;

//controller
bool gameStart = 0;
bool inGame = 0;
bool getHint1 = 0;
bool getHint2 = 0;
bool getHint3 = 0;
bool getHint4 = 0;
bool playMenuMix = 0;
bool playGameMix = 0;
bool onQuest1 = 0;
bool onQuest2 = 0;
bool onQuest3 = 0;
bool onQuest4 = 0;
bool can4 = 1;
bool can3 = 1;
bool can2 = 1;
bool can1 = 1;
bool gotKey = 0;


//
SDL_Renderer* Game::renderer = nullptr ;
//
Manager manager;
//
SDL_Event Game::event;
//



auto& background(manager.addEntity());
auto& botBorder(manager.addEntity());
auto& leftBorder(manager.addEntity());
auto& topBorder(manager.addEntity());
auto& rightBorder(manager.addEntity());
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
auto& fence1(manager.addEntity());
auto& fence2(manager.addEntity());
auto& fence3(manager.addEntity());
auto& fence4(manager.addEntity());
auto& scroll1(manager.addEntity());
auto& scroll2(manager.addEntity());
auto& scroll3(manager.addEntity());
auto& scroll4(manager.addEntity());
auto& screen(manager.addEntity());
auto& chest(manager.addEntity());
auto& pwup(manager.addEntity());
auto& player(manager.addEntity());
auto& key(manager.addEntity());
auto& life(manager.addEntity());
//akainu phase
auto& lava1(manager.addEntity());
auto& lava2(manager.addEntity());
auto& lava3(manager.addEntity());
auto& lava4(manager.addEntity());
auto& lava5(manager.addEntity());
auto& akainu(manager.addEntity());
//kuzan phase
auto& kuzan(manager.addEntity());
//after interact
auto& hint1(manager.addEntity());

auto& hint2(manager.addEntity());

auto& hint3(manager.addEntity());

auto& hint4(manager.addEntity());

//effect

//menu
auto& menu(manager.addEntity());
auto& menu2(manager.addEntity());


//question
auto& quest1(manager.addEntity());
auto& quest2(manager.addEntity());
auto& quest3(manager.addEntity());
auto& quest4(manager.addEntity());



Game::Game()
{

}
Game::~Game()
{

}

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
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        isRunning = true;
        menuMix = Mix_LoadWAV("Mixer/menu.wav");
        gameMix = Mix_LoadWAV("Mixer/game.wav");
        trueMix = Mix_LoadWAV("Mixer/true.wav");
        falseMix = Mix_LoadWAV("Mixer/wrong.wav");
        scoreText->loadFont("monogram-extended.ttf",80);
    }
    else isRunning = false;



    menu.addComponent<TransformComponent>(0,0,gHeight,gWidth,1);
    menu.addComponent<SpriteComponent>("GUI/menu.png");

    background.addComponent<TransformComponent>(0, 0, gHeight, gWidth,1);
    background.addComponent<SpriteComponent>("GUI/background.png");


    player.addComponent<TransformComponent>(16,320,56,32,1);
    player.addComponent<SpriteComponent>("GUI/player.png",1);
    player.addComponent<KeyboardHandling>();
    player.addComponent<ColliderComponent>("player");


    botBorder.addComponent<TransformComponent>(0,gHeight-16,16,gWidth,1);
    botBorder.addComponent<ColliderComponent>("botBorder");

    leftBorder.addComponent<TransformComponent>(0,0, gHeight, 16, 1);
    leftBorder.addComponent<ColliderComponent>("lBorder");

    screen.addComponent<TransformComponent>(215,375,165,320,1);
    screen.addComponent<ColliderComponent>("screen");


    topBorder.addComponent<TransformComponent>(0,-10,10,gWidth,1);
    topBorder.addComponent<ColliderComponent>("topBorder");

    rightBorder.addComponent<TransformComponent>(1280,0,gHeight,14,1);
    rightBorder.addComponent<ColliderComponent>("rBorder");


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

    lava1.addComponent<TransformComponent>(168,210, 40, 40, 1);
    lava1.addComponent<SpriteComponent>("GUI/lava_.png",1);
    lava1.addComponent<ColliderComponent>("lava1");

    lava2.addComponent<TransformComponent>(272,81, 40, 40, 1);
    lava2.addComponent<SpriteComponent>("GUI/lava_.png",1);
    lava2.addComponent<ColliderComponent>("lava1");

    lava3.addComponent<TransformComponent>(359,169, 40, 40, 1);
    lava3.addComponent<SpriteComponent>("GUI/lava_.png",1);
    lava3.addComponent<ColliderComponent>("lava1");

    lava4.addComponent<TransformComponent>(444,19, 40, 40, 1);
    lava4.addComponent<SpriteComponent>("GUI/lava.png",1);
    lava4.addComponent<ColliderComponent>("lava1");
    lava4.addComponent<AutoComponent>(0,1);

    lava5.addComponent<TransformComponent>(541,169, 40, 40, 1);
    lava5.addComponent<SpriteComponent>("GUI/lava.png",1);
    lava5.addComponent<ColliderComponent>("lava1");
    lava5.addComponent<AutoComponent>(0,2);

    akainu.addComponent<TransformComponent>(665,19,128,64,1);
    akainu.addComponent<SpriteComponent>("GUI/Akainu.png",1);
    akainu.getComponent<SpriteComponent>().speed = 200;
    akainu.getComponent<SpriteComponent>().spriteflip = SDL_FLIP_HORIZONTAL;



    kuzan.addComponent<TransformComponent>(730,400,128,64,1);
    kuzan.addComponent<SpriteComponent>("GUI/Kuzan.png",1);
    kuzan.getComponent<SpriteComponent>().speed = 200;
    kuzan.getComponent<SpriteComponent>().spriteflip = SDL_FLIP_HORIZONTAL;

    chest.addComponent<TransformComponent>(1240,540,40,40,1);
    chest.addComponent<SpriteComponent>("GUI/chest.png");
    chest.addComponent<ColliderComponent>("chest");

    key.addComponent<TransformComponent>(32,68,40,40,1);
    key.addComponent<SpriteComponent>("GUI/key.png");

    hint1.addComponent<TransformComponent>(215,375,85,160,1);
    hint1.addComponent<SpriteComponent>("GUI/cover.png");

    scroll1.addComponent<TransformComponent>(855,151,40,40,1);
    scroll1.addComponent<SpriteComponent>("GUI/scroll.png");


    hint2.addComponent<TransformComponent>(375,375,85,160,1);
    hint2.addComponent<SpriteComponent>("GUI/cover.png");

    scroll2.addComponent<TransformComponent>(600,140,40,40,1);
    scroll2.addComponent<SpriteComponent>("GUI/scroll.png");
    scroll2.addComponent<ColliderComponent>("scroll2");

    hint3.addComponent<TransformComponent>(215,455,85,160,1);
    hint3.addComponent<SpriteComponent>("GUI/cover.png");

    scroll3.addComponent<TransformComponent>(920,478,40,40,1);
    scroll3.addComponent<SpriteComponent>("GUI/scroll.png");
    scroll3.addComponent<ColliderComponent>("scroll3");

    hint4.addComponent<TransformComponent>(375,455,85,160,1);
    hint4.addComponent<SpriteComponent>("GUI/cover.png");

    scroll4.addComponent<TransformComponent>(170,145,40,40,1);
    scroll4.addComponent<SpriteComponent>("GUI/scroll.png");
    scroll4.addComponent<ColliderComponent>("scroll4");


    quest1.addComponent<TransformComponent>(0,0,640,1280,1);
    quest1.addComponent<SpriteComponent>();

    quest2.addComponent<TransformComponent>(0,0,640,1280,1);
    quest2.addComponent<SpriteComponent>();

    quest3.addComponent<TransformComponent>(0,0,640,1280,1);
    quest3.addComponent<SpriteComponent>();

    quest4.addComponent<TransformComponent>(0,0,640,1280,1);
    quest4.addComponent<SpriteComponent>();

    life.addComponent<TransformComponent>(16,24,40,300,1);
    life.addComponent<SpriteComponent>("GUI/hp.png");

    fence4.addComponent<TransformComponent>(1030, 18,603,9,1 );
    fence4.addComponent<SpriteComponent>("GUI/fence4.png");
    fence4.addComponent<ColliderComponent>("fence4");

    fence3.addComponent<TransformComponent>(752, 530,93,10,1 );
    fence3.addComponent<SpriteComponent>("GUI/fence3.png");
    fence3.addComponent<ColliderComponent>("fence3");

    fence2.addComponent<TransformComponent>(720, 257,16,180,1 );
    fence2.addComponent<SpriteComponent>("GUI/fence2.png");
    fence2.addComponent<ColliderComponent>("fence2");

    fence1.addComponent<TransformComponent>(400, 20,120,16,1 );
    fence1.addComponent<SpriteComponent>("GUI/fence1.png");
    fence1.addComponent<ColliderComponent>("fence1");


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
    Vector2D playerPos = player.getComponent<TransformComponent>().position ;
	manager.refresh();
	manager.update();

    score -= 100;

    //print life
    switch(HP)
    {
    case 4:
        life.getComponent<SpriteComponent>().setTex("GUI/hp-1.png");
        break;
    case 3:
        life.getComponent<SpriteComponent>().setTex("GUI/hp-2.png");
        break;
    case 2:
        life.getComponent<SpriteComponent>().setTex("GUI/hp-3.png");
        break;
    case 1:
        life.getComponent<SpriteComponent>().setTex("GUI/hp-4.png");
        break;
    case 0:
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"ADMIN","YOU DIED",window);
        isRunning = false;
        break;

    }
    //got key

    //play mix
    if(!gameStart&&playMenuMix==0){Mix_PlayChannel(-1,menuMix,-1);
        playMenuMix=1;
    }
    else if(gameStart) {

        if(!inGame)Mix_HaltChannel(-1);
        inGame = 1;
        if(!playGameMix)
        {
            Mix_PlayChannel(-1,gameMix,-1);
            playGameMix = 1;
        }



    }

    //lavacol
    if(Collision::AABB(lava4.getComponent<ColliderComponent>().collider,grass7.getComponent<ColliderComponent>().collider))
    {
        lava4.getComponent<AutoComponent>().dir = -1;
    }
    if(Collision::AABB(lava4.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        lava4.getComponent<AutoComponent>().dir = 1;
    }
    if(Collision::AABB(lava5.getComponent<ColliderComponent>().collider,grass6.getComponent<ColliderComponent>().collider))
    {
        lava5.getComponent<AutoComponent>().dir = -1;
    }
    if(Collision::AABB(lava5.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        lava5.getComponent<AutoComponent>().dir = 1;
    }

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,lava1.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().position = startPos;
        HP-=1;

    }
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,lava3.getComponent<ColliderComponent>().collider)
            ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava4.getComponent<ColliderComponent>().collider)
            ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava5.getComponent<ColliderComponent>().collider)
            ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava2.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().position = startPos;
        HP-=1;

    }

	//std::cout<<mx<<" "<<my<<std::endl;

	//quest 1

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,rock1.getComponent<ColliderComponent>().collider)&&(!getHint1))
    {

        onQuest1 = 1;

    }

    if(onQuest1 == 1)
    {
        quest1.getComponent<SpriteComponent>().setTex("GUI/quest1.png");
        hint1.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_6)
        {
            Mix_PlayChannel(1,trueMix,1);

            quest1.getComponent<SpriteComponent>().Free();
            fence4.getComponent<SpriteComponent>().Free();

            onQuest1 = 0;
            getHint1 = 1;
            can4 = 0;
        }


    }

    //quest 2


    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,scroll2.getComponent<ColliderComponent>().collider)&&(!getHint2))
    {

        onQuest2 = 1;

    }

    if(onQuest2 == 1)
    {
        quest2.getComponent<SpriteComponent>().setTex("GUI/quest2.png");
        hint2.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_2)
        {
            Mix_PlayChannel(2,trueMix,1);
            quest2.getComponent<SpriteComponent>().Free();
            fence3.getComponent<SpriteComponent>().Free();


            can3 = 0;
            onQuest2 = 0;
            getHint2 = 1;

        }

    }

    //quest3

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,scroll3.getComponent<ColliderComponent>().collider)&&(!getHint3))
    {

        onQuest3 = 1;

    }

    if(onQuest3 == 1)
    {
        quest3.getComponent<SpriteComponent>().setTex("GUI/quest3.png");
        hint3.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_0)
        {
            Mix_PlayChannel(3,trueMix,1);

            quest3.getComponent<TransformComponent>().Free();
            fence2.getComponent<SpriteComponent>().Free();
            can2 = 0;
            onQuest3 = 0;
            getHint3 = 1;
        }

    }

    //quest4

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,scroll4.getComponent<ColliderComponent>().collider)&&(!getHint4))
    {

        onQuest4 = 1;

    }
    if(onQuest4 == 1)
    {
        quest4.getComponent<SpriteComponent>().setTex("GUI/quest4.png");
        hint4.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_d)
        {
            Mix_PlayChannel(4,trueMix,1);

            quest4.getComponent<SpriteComponent>().Free();
            fence1.getComponent<SpriteComponent>().Free();

            can1 = 0;
            onQuest4 = 0;
            getHint4 = 1;
        }

    }




    if(can4==0)
    {
        gotKey = true;
        key.getComponent<SpriteComponent>().setTex("GUI/key1.png");

    }
    if(gotKey&&Collision::AABB(player.getComponent<ColliderComponent>().collider, chest.getComponent<ColliderComponent>().collider))
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT,"CONGRATULATION","YOU WIN",window);
        isRunning = false;
    }


	if (  Collision::AABB(player.getComponent<ColliderComponent>().collider, botBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, topBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rightBorder.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, leftBorder.getComponent<ColliderComponent>().collider)
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
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, rock5.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider, screen.getComponent<ColliderComponent>().collider)
        ||(Collision::AABB(player.getComponent<ColliderComponent>().collider, fence1.getComponent<ColliderComponent>().collider)&&can1==1)
        ||(Collision::AABB(player.getComponent<ColliderComponent>().collider, fence3.getComponent<ColliderComponent>().collider)&&can3==1)
        ||(Collision::AABB(player.getComponent<ColliderComponent>().collider, fence4.getComponent<ColliderComponent>().collider)&&can4==1)
        ||(Collision::AABB(player.getComponent<ColliderComponent>().collider, fence2.getComponent<ColliderComponent>().collider)&&can2==1)
        ){
            player.getComponent<TransformComponent>().position = playerPos;
            std::cout << "Collision!" << std::endl;
	}




}
void Game::render()
{
    SDL_RenderClear(renderer);
    manager.draw();
    scoreText->setText(std::to_string(score),{255, 255, 255, 255});
    scoreText->render(675,16);


    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    Mix_FreeChunk(gameMix);
    Mix_FreeChunk(menuMix);
    Mix_FreeChunk(trueMix);
    Mix_FreeChunk(falseMix);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
