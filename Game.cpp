#include"Game.h"
#include"Textures.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "KeyboardHandling.h"
#include "Collision.h"
#include "iostream"
#include "vector"
#include"string"
//init elements

int mx = rand()%1228 + 1041;

int my = rand()%490 + 20;

int HP = 5;

int score = 140000;

Vector2D startPos(16,320);

Vector2D ranPos(mx,my);

//mix init

Mix_Chunk *guideMix = NULL;
Mix_Chunk *menuMix = NULL;
Mix_Chunk *gameMix = NULL;
Mix_Chunk *trueMix = NULL;
Mix_Chunk *hitMix = NULL;
Mix_Chunk *catchMix = NULL;
Mix_Chunk *endMix = NULL;

//controller
bool gameStart = 0;
bool inGame = 0;
bool getHint1 = 0;
bool getHint2 = 0;
bool getHint3 = 0;
bool getHint4 = 0;
bool getKit1 = 0;
bool getKit2 = 0;
bool getKit3 = 0;
bool getKit4 = 0;
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
bool turn1 = 0;
bool turn2 = 0;
bool turn3 = 0;
bool turn4 = 0;
bool gotKb = 0;
bool gameOver = 0;
bool over = 0;
bool victoryMix = 0;
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
auto& life(manager.addEntity());
auto& partner(manager.addEntity());
auto& medkit1(manager.addEntity());
auto& medkit2(manager.addEntity());
auto& medkit3(manager.addEntity());
auto& medkit4(manager.addEntity());
//akainu phase
auto& lava1(manager.addEntity());
auto& lava2(manager.addEntity());
auto& lava3(manager.addEntity());
auto& lava4(manager.addEntity());
auto& lava5(manager.addEntity());
auto& akainu(manager.addEntity());
//kuzan phase
auto& lim1(manager.addEntity());
auto& lim2(manager.addEntity());
auto& lim3(manager.addEntity());
auto& frost1(manager.addEntity());
auto& frost2(manager.addEntity());
auto& frost3(manager.addEntity());
auto& frost4(manager.addEntity());
auto& frost5(manager.addEntity());
auto& frost6(manager.addEntity());
auto& iceSl3(manager.addEntity());
auto& iceSl1(manager.addEntity());
auto& iceSl2(manager.addEntity());
auto& iceSp1(manager.addEntity());
auto& iceSp2(manager.addEntity());
auto& floatIce1(manager.addEntity());
auto& floatIce2(manager.addEntity());
auto& floatIce3(manager.addEntity());
auto& floatIce4(manager.addEntity());
auto& kuzan(manager.addEntity());
//kizaru phase
auto& flash1(manager.addEntity());
auto& flash2(manager.addEntity());
auto& flash3(manager.addEntity());
auto& flash4(manager.addEntity());
auto& flash5(manager.addEntity());
auto& lightBall1(manager.addEntity());
auto& lightBall2(manager.addEntity());
auto& lightBall3(manager.addEntity());
auto& lightBall4(manager.addEntity());
auto& lightBall5(manager.addEntity());
auto& lightBall6(manager.addEntity());
auto& lightBall7(manager.addEntity());
auto& lightBall8(manager.addEntity());
auto& kizaru(manager.addEntity());
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
//gameover
auto& endGame(manager.addEntity());
int kb = 1;

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
        guideMix = Mix_LoadWAV("Mixer/guide.wav");
        menuMix = Mix_LoadWAV("Mixer/menu.wav");
        gameMix = Mix_LoadWAV("Mixer/game.wav");
        trueMix = Mix_LoadWAV("Mixer/true.wav");
        hitMix = Mix_LoadWAV("Mixer/hit.wav");
        catchMix = Mix_LoadWAV("Mixer/medkit.wav");
        endMix = Mix_LoadWAV("Mixer/gameover.wav");

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

    medkit1.addComponent<TransformComponent>(534,25,32,32,1);
    medkit1.addComponent<SpriteComponent>("GUI/medkit.png",1);
    medkit1.addComponent<ColliderComponent>("mk1");

    medkit2.addComponent<TransformComponent>(725,150,32,32,1);
    medkit2.addComponent<SpriteComponent>("GUI/medkit.png",1);
    medkit2.addComponent<ColliderComponent>("mk2");

    medkit3.addComponent<TransformComponent>(980,535,32,32,1);
    medkit3.addComponent<SpriteComponent>("GUI/medkit.png",1);
    medkit3.addComponent<ColliderComponent>("mk2");

    medkit4.addComponent<TransformComponent>(1150,325,32,32,1);
    medkit4.addComponent<SpriteComponent>("GUI/medkit.png",1);
    medkit4.addComponent<ColliderComponent>("mk2");

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
    //
    lim1.addComponent<TransformComponent>(848,144,2,192,1);
    lim1.addComponent<ColliderComponent>("lim1");

    lim2.addComponent<TransformComponent>(721,529,1,319,1);
    lim2.addComponent<ColliderComponent>("lim1");

    lim3.addComponent<TransformComponent>(1040,19,620,1,1);
    lim3.addComponent<ColliderComponent>("lim3");
    frost1.addComponent<TransformComponent>(920,295,40,40,1);
    frost1.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost1.getComponent<SpriteComponent>().speed = 200;
    frost1.addComponent<ColliderComponent>("frost1");

    frost2.addComponent<TransformComponent>(920,343,40,40,1);
    frost2.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost2.getComponent<SpriteComponent>().speed = 200;
    frost2.addComponent<ColliderComponent>("frost2");

    frost3.addComponent<TransformComponent>(550,330,40,40,1);
    frost3.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost3.getComponent<SpriteComponent>().speed = 200;
    frost3.addComponent<ColliderComponent>("frost3");

    frost4.addComponent<TransformComponent>(555,472,40,40,1);
    frost4.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost4.getComponent<SpriteComponent>().speed = 200;
    frost4.addComponent<ColliderComponent>("frost4");

    frost5.addComponent<TransformComponent>(675,360,40,40,1);
    frost5.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost5.getComponent<SpriteComponent>().speed = 200;
    frost5.addComponent<ColliderComponent>("frost5");

    frost6.addComponent<TransformComponent>(815,391,40,40,1);
    frost6.addComponent<SpriteComponent>("GUI/frost.png",1);
    frost6.getComponent<SpriteComponent>().speed = 200;
    frost6.addComponent<ColliderComponent>("frost6");

    iceSl1.addComponent<TransformComponent>(596,317,50,156,1);
    iceSl1.addComponent<ColliderComponent>("isl1");

    iceSl2.addComponent<TransformComponent>(818,317,70,120,1);
    iceSl2.addComponent<ColliderComponent>("isl2");

    iceSl3.addComponent<TransformComponent>(602,467,50,60,1);
    iceSl3.addComponent<ColliderComponent>("isl_1");

    floatIce1.addComponent<TransformComponent>(860,18,30,30,1);
    floatIce1.addComponent<SpriteComponent>("GUI/floatice.png",1);
    floatIce1.addComponent<ColliderComponent>("flIce1");
    floatIce1.addComponent<AutoComponent>(0,2);

    floatIce2.addComponent<TransformComponent>(947,106,30,30,1);
    floatIce2.addComponent<SpriteComponent>("GUI/floatice.png",1);
    floatIce2.addComponent<ColliderComponent>("flIce2");
    floatIce2.addComponent<AutoComponent>(0,3);

    floatIce3.addComponent<TransformComponent>(760,531,25,30,1);
    floatIce3.addComponent<SpriteComponent>("GUI/floatice.png",1);
    floatIce3.addComponent<ColliderComponent>("flIce3");
    floatIce3.addComponent<AutoComponent>(0,0.5);

    floatIce4.addComponent<TransformComponent>(850,584,25,30,1);
    floatIce4.addComponent<SpriteComponent>("GUI/floatice.png",1);
    floatIce4.addComponent<ColliderComponent>("flIce4");
    floatIce4.addComponent<AutoComponent>(0,0.5);

    iceSp1.addComponent<TransformComponent>(735,318,48,64,1);
    iceSp1.addComponent<SpriteComponent>("GUI/icespell.png",1);
    iceSp1.addComponent<ColliderComponent>("icesp1");

    iceSp2.addComponent<TransformComponent>(735,387,48,64,1);
    iceSp2.addComponent<SpriteComponent>("GUI/icespell.png",1);
    iceSp2.addComponent<ColliderComponent>("icesp2");

    kuzan.addComponent<TransformComponent>(840,400,128,64,1);
    kuzan.addComponent<SpriteComponent>("GUI/Kuzan.png",1);
    kuzan.getComponent<SpriteComponent>().speed = 200;
    kuzan.getComponent<SpriteComponent>().spriteflip = SDL_FLIP_HORIZONTAL;
    //
    flash1.addComponent<TransformComponent>(1040,150,40,40,1);
    flash1.addComponent<SpriteComponent>("GUI/flash.png",1);
    flash1.addComponent<ColliderComponent>("flash1");
    flash1.addComponent<AutoComponent>(-2,0);

    flash2.addComponent<TransformComponent>(1238,282,40,40,1);
    flash2.addComponent<SpriteComponent>("GUI/flash.png",1);
    flash2.addComponent<ColliderComponent>("flash1");
    flash2.addComponent<AutoComponent>(2,0);

    flash3.addComponent<TransformComponent>(1040,403,40,40,1);
    flash3.addComponent<SpriteComponent>("GUI/flash.png",1);
    flash3.addComponent<ColliderComponent>("flash1");
    flash3.addComponent<AutoComponent>(-2,0);

    flash4.addComponent<TransformComponent>(1238,497,40,40,1);
    flash4.addComponent<SpriteComponent>("GUI/flash.png",1);
    flash4.addComponent<ColliderComponent>("flash1");
    flash4.addComponent<AutoComponent>(2,0);

    flash5.addComponent<TransformComponent>(1040,555,40,40,1);
    flash5.addComponent<SpriteComponent>("GUI/flash.png",1);
    flash5.addComponent<ColliderComponent>("flash1");
    flash5.addComponent<AutoComponent>(-2,0);

    lightBall1.addComponent<TransformComponent>(1050,22,20,20,1);
    lightBall1.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall1.addComponent<ColliderComponent>("lb1");
    lightBall1.addComponent<AutoComponent>(-1,-1);

    lightBall2.addComponent<TransformComponent>(1242,22,20,20,1);
    lightBall2.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall2.addComponent<ColliderComponent>("lb2");
    lightBall2.addComponent<AutoComponent>(1,1);

    lightBall3.addComponent<TransformComponent>(1050,232,20,20,1);
    lightBall3.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall3.addComponent<ColliderComponent>("lb3");
    lightBall3.addComponent<AutoComponent>(-1,-1);

    lightBall4.addComponent<TransformComponent>(1242,232,20,20,1);
    lightBall4.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall4.addComponent<ColliderComponent>("lb4");
    lightBall4.addComponent<AutoComponent>(1,1);

    lightBall5.addComponent<TransformComponent>(1050,443,20,20,1);
    lightBall5.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall5.addComponent<ColliderComponent>("lb5");
    lightBall5.addComponent<AutoComponent>(-1,-1);

    lightBall6.addComponent<TransformComponent>(1242,443,20,20,1);
    lightBall6.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall6.addComponent<ColliderComponent>("lb6");
    lightBall6.addComponent<AutoComponent>(1,1);

    lightBall7.addComponent<TransformComponent>(1050,535,20,20,1);
    lightBall7.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall7.addComponent<ColliderComponent>("lb7");
    lightBall7.addComponent<AutoComponent>(-1,-1);

    lightBall8.addComponent<TransformComponent>(1242,535,20,20,1);
    lightBall8.addComponent<SpriteComponent>("GUI/lightball.png",1);
    lightBall8.addComponent<ColliderComponent>("lb6");
    lightBall8.addComponent<AutoComponent>(1,1);

    kizaru.addComponent<TransformComponent>(982,292,128,64,1);
    kizaru.addComponent<SpriteComponent>("GUI/Kizaru.png",1);
    kizaru.getComponent<SpriteComponent>().speed = 200;

    chest.addComponent<TransformComponent>(1240,540,40,40,1);
    chest.addComponent<SpriteComponent>("GUI/chest.png");
    chest.addComponent<ColliderComponent>("chest");

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

    fence2.addComponent<TransformComponent>(720, 235,12,180,1 );
    fence2.addComponent<SpriteComponent>("GUI/fence2.png");
    fence2.addComponent<ColliderComponent>("fence2");

    fence1.addComponent<TransformComponent>(400, 20,120,16,1 );
    fence1.addComponent<SpriteComponent>("GUI/fence1.png");
    fence1.addComponent<ColliderComponent>("fence1");

    endGame.addComponent<TransformComponent>(0,0,640,1280,1);
    endGame.addComponent<SpriteComponent>();
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
            else if (!gameStart&&mx>=568&&mx<=717&&my>=495&&my<=528){
                menu.getComponent<SpriteComponent>().setTex("GUI/guide.png");
                Mix_PlayChannel(-1,guideMix,0);
            }
            else if (gameOver&&mx>=537&&mx<=779&&my>=438&&my<=526)
            {
                isRunning = false;
            }
            break;

    }
}

void Game::update() {

    Vector2D playerPos = player.getComponent<TransformComponent>().position ;
	manager.refresh();
	manager.update();

    score -= 1;
    std::cout<<score<<std::endl;
    if(score==0){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"GAME OVER","OUT OF TIME, YOU STARVED TO DEATH",window);
        isRunning = false;
    }

    //print life
    switch(HP)
    {
    case 5:
        life.getComponent<SpriteComponent>().setTex("GUI/hp.png");
        break;
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
    else if(gameOver) {
        if(!over)Mix_HaltChannel(-1);
        over = 1;
        if(!victoryMix){
            Mix_PlayChannel(-1,endMix,-1);
            victoryMix = 1;
        }
    }


    //lava collision
    if(Collision::AABB(lava4.getComponent<ColliderComponent>().collider,grass7.getComponent<ColliderComponent>().collider))
    {
        lava4.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lava4.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        lava4.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(lava5.getComponent<ColliderComponent>().collider,grass6.getComponent<ColliderComponent>().collider))
    {
        lava5.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lava5.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        lava5.getComponent<AutoComponent>().dirY = 1;
    }

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,lava1.getComponent<ColliderComponent>().collider)||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava3.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava4.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava5.getComponent<ColliderComponent>().collider)
        ||Collision::AABB(player.getComponent<ColliderComponent>().collider,lava2.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,hitMix,0);
        player.getComponent<TransformComponent>().position = startPos;
        HP-=1;
    }

    //frozen collision
    if(Collision::AABB(floatIce1.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        floatIce1.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(floatIce1.getComponent<ColliderComponent>().collider,lim1.getComponent<ColliderComponent>().collider))
    {
        floatIce1.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(floatIce2.getComponent<ColliderComponent>().collider,topBorder.getComponent<ColliderComponent>().collider))
    {
        floatIce2.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(floatIce2.getComponent<ColliderComponent>().collider,lim1.getComponent<ColliderComponent>().collider))
    {
        floatIce2.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(floatIce3.getComponent<ColliderComponent>().collider,lim2.getComponent<ColliderComponent>().collider))
    {
        floatIce3.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(floatIce3.getComponent<ColliderComponent>().collider,botBorder.getComponent<ColliderComponent>().collider))
    {
        floatIce3.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(floatIce4.getComponent<ColliderComponent>().collider,lim2.getComponent<ColliderComponent>().collider))
    {
        floatIce4.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(floatIce4.getComponent<ColliderComponent>().collider,botBorder.getComponent<ColliderComponent>().collider))
    {
        floatIce4.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, iceSl1.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, iceSl3.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().position.x -= 3;
    }
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, iceSl2.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().position.x += 3;
    }
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, iceSp1.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, iceSp2.getComponent<ColliderComponent>().collider))
    {
            player.getComponent<TransformComponent>().velocity*-1;
    }

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, frost1.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, frost2.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, frost3.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, frost4.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, frost5.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, frost6.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, floatIce1.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, floatIce2.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, floatIce3.getComponent<ColliderComponent>().collider)
       || Collision::AABB(player.getComponent<ColliderComponent>().collider, floatIce4.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,hitMix,0);
        player.getComponent<TransformComponent>().position = startPos;
        HP-=1;
    }
    //medkit collision
    if(!getKit1&&Collision::AABB(player.getComponent<ColliderComponent>().collider, medkit1.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,catchMix,0);
        medkit1.getComponent<SpriteComponent>().Free();
        if(HP<5) HP+=1;
        getKit1 = 1;
    }
    if(!getKit2&&Collision::AABB(player.getComponent<ColliderComponent>().collider, medkit2.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,catchMix,0);
        medkit2.getComponent<SpriteComponent>().Free();
        if(HP<5) HP+=1;
        getKit2 = 1;
    }
    if(!getKit3&&Collision::AABB(player.getComponent<ColliderComponent>().collider, medkit3.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,catchMix,0);
        medkit3.getComponent<SpriteComponent>().Free();
        if(HP<5) HP+=1;
        getKit3 = 1;
    }
    if(!getKit4&&Collision::AABB(player.getComponent<ColliderComponent>().collider, medkit4.getComponent<ColliderComponent>().collider))
    {
        Mix_PlayChannel(-1,catchMix,0);
        medkit4.getComponent<SpriteComponent>().Free();
        if(HP<5) HP+=1;
        getKit4 = 1;
    }
    //kizaru collision
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, flash1.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, flash2.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, flash3.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, flash4.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().position = ranPos;
    }

    if(!gameOver&&(Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall1.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall2.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall3.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall4.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall5.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall6.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall7.getComponent<ColliderComponent>().collider)
       ||Collision::AABB(player.getComponent<ColliderComponent>().collider, lightBall8.getComponent<ColliderComponent>().collider)))
    {
        Mix_PlayChannel(-1,hitMix,0);
        player.getComponent<TransformComponent>().position = startPos;
        HP--;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall1.getComponent<ColliderComponent>().collider))
    {
        lightBall1.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall1.getComponent<ColliderComponent>().collider))
    {
        lightBall1.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall1.getComponent<ColliderComponent>().collider))
    {
        lightBall1.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall1.getComponent<ColliderComponent>().collider))
    {
        lightBall1.getComponent<AutoComponent>().dirY = 1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall3.getComponent<ColliderComponent>().collider))
    {
        lightBall3.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall3.getComponent<ColliderComponent>().collider))
    {
        lightBall3.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall3.getComponent<ColliderComponent>().collider))
    {
        lightBall3.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall3.getComponent<ColliderComponent>().collider))
    {
        lightBall3.getComponent<AutoComponent>().dirY = 1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall5.getComponent<ColliderComponent>().collider))
    {
        lightBall5.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall5.getComponent<ColliderComponent>().collider))
    {
        lightBall5.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall5.getComponent<ColliderComponent>().collider))
    {
        lightBall5.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall5.getComponent<ColliderComponent>().collider))
    {
        lightBall5.getComponent<AutoComponent>().dirY = 1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall7.getComponent<ColliderComponent>().collider))
    {
        lightBall7.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall7.getComponent<ColliderComponent>().collider))
    {
        lightBall7.getComponent<AutoComponent>().dirY = -1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall7.getComponent<ColliderComponent>().collider))
    {
        lightBall7.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall7.getComponent<ColliderComponent>().collider))
    {
        lightBall7.getComponent<AutoComponent>().dirY = 1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall2.getComponent<ColliderComponent>().collider))
    {
        lightBall2.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall2.getComponent<ColliderComponent>().collider))
    {
        lightBall2.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall2.getComponent<ColliderComponent>().collider))
    {
        lightBall2.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall2.getComponent<ColliderComponent>().collider))
    {
        lightBall2.getComponent<AutoComponent>().dirY = -1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall4.getComponent<ColliderComponent>().collider))
    {
        lightBall4.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall4.getComponent<ColliderComponent>().collider))
    {
        lightBall4.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall4.getComponent<ColliderComponent>().collider))
    {
        lightBall4.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall4.getComponent<ColliderComponent>().collider))
    {
        lightBall4.getComponent<AutoComponent>().dirY = -1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall6.getComponent<ColliderComponent>().collider))
    {
        lightBall6.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall6.getComponent<ColliderComponent>().collider))
    {
        lightBall6.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall6.getComponent<ColliderComponent>().collider))
    {
        lightBall6.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall6.getComponent<ColliderComponent>().collider))
    {
        lightBall6.getComponent<AutoComponent>().dirY = -1;
    }
//
    if(Collision::AABB(rightBorder.getComponent<ColliderComponent>().collider, lightBall8.getComponent<ColliderComponent>().collider))
    {
        lightBall8.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(topBorder.getComponent<ColliderComponent>().collider, lightBall8.getComponent<ColliderComponent>().collider))
    {
        lightBall8.getComponent<AutoComponent>().dirY = 1;
    }
    if(Collision::AABB(lim3.getComponent<ColliderComponent>().collider, lightBall8.getComponent<ColliderComponent>().collider))
    {
        lightBall8.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(botBorder.getComponent<ColliderComponent>().collider, lightBall8.getComponent<ColliderComponent>().collider))
    {
        lightBall8.getComponent<AutoComponent>().dirY = -1;
    }
//
    if(Collision::AABB(flash1.getComponent<ColliderComponent>().collider,lim3.getComponent<ColliderComponent>().collider))
    {
        flash1.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(flash1.getComponent<ColliderComponent>().collider,rightBorder.getComponent<ColliderComponent>().collider))
    {
        flash1.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(flash3.getComponent<ColliderComponent>().collider,lim3.getComponent<ColliderComponent>().collider))
    {
        flash3.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(flash3.getComponent<ColliderComponent>().collider,rightBorder.getComponent<ColliderComponent>().collider))
    {
        flash3.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(flash4.getComponent<ColliderComponent>().collider,lim3.getComponent<ColliderComponent>().collider))
    {
        flash4.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(flash4.getComponent<ColliderComponent>().collider,rightBorder.getComponent<ColliderComponent>().collider))
    {
        flash4.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(flash2.getComponent<ColliderComponent>().collider,lim3.getComponent<ColliderComponent>().collider))
    {
        flash2.getComponent<AutoComponent>().dirX = 1;
    }
    if(Collision::AABB(flash2.getComponent<ColliderComponent>().collider,rightBorder.getComponent<ColliderComponent>().collider))
    {
        flash2.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(flash5.getComponent<ColliderComponent>().collider,lim3.getComponent<ColliderComponent>().collider))
    {
        flash5.getComponent<AutoComponent>().dirX = -1;
    }
    if(Collision::AABB(flash5.getComponent<ColliderComponent>().collider,rightBorder.getComponent<ColliderComponent>().collider))
    {
        flash5.getComponent<AutoComponent>().dirX = 1;
    }
    //q&a
	//quest 1
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,rock1.getComponent<ColliderComponent>().collider)&&(!getHint1))
    {
        onQuest1 = 1;
    }

    if(onQuest1 == 1)
    {
        if(!turn1){
            quest1.getComponent<SpriteComponent>().setTex("GUI/quest1.png");
            turn1=1;
        }
        hint1.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_6)
        {
            Mix_PlayChannel(-1,trueMix,0);
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
        if(!turn2){
            quest2.getComponent<SpriteComponent>().setTex("GUI/quest2.png");
            turn2 = true;
        }
        hint2.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_2)
        {
            Mix_PlayChannel(-1,trueMix,0);
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
        if(!turn3){
            quest3.getComponent<SpriteComponent>().setTex("GUI/quest3.png");
            turn3 = true;
        }
        hint3.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_0)
        {
            Mix_PlayChannel(-1,trueMix,0);
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
        if(!turn4){
            quest4.getComponent<SpriteComponent>().setTex("GUI/quest4.png");
            turn4 = true;
        }
        hint4.getComponent<SpriteComponent>().Free();
        if(event.key.keysym.sym==SDLK_d)
        {
            Mix_PlayChannel(-1,trueMix,0);
            quest4.getComponent<SpriteComponent>().Free();
            fence1.getComponent<SpriteComponent>().Free();
            can1 = 0;
            onQuest4 = 0;
            getHint4 = 1;
        }

    }
    //got the key
    if(can4==0)
    {
        gotKey = true;
    }
    if(!gameOver&&gotKey&&Collision::AABB(player.getComponent<ColliderComponent>().collider, chest.getComponent<ColliderComponent>().collider))
    {
        if(kb==1)
            endGame.getComponent<SpriteComponent>().setTex("GUI/khobau1.png");
        else if(kb==2)
            endGame.getComponent<SpriteComponent>().setTex("GUI/khobau2.png");
        else if(kb==3)
            endGame.getComponent<SpriteComponent>().setTex("GUI/khobau3.png");
        gameOver = 1;
    }


    //common collide
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
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    Mix_FreeChunk(gameMix);
    Mix_FreeChunk(menuMix);
    Mix_FreeChunk(trueMix);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
