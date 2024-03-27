#include"Game.h"
SDL_Texture *mCharacterTex;
SDL_Rect srcR, destR;
Game::Game()
{

}
Game::~Game(){}
void Game::init(const char* title,int posx, int posy, int width, int height, bool fullscreen)
{

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std::cout<<"khoitaothanhcong"<<std::endl;

        window = SDL_CreateWindow(title,posx,posy,width,height,SDL_WINDOW_SHOWN);
        if(window){
            std::cout<<"windowcreated"<<std::endl;
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            std::cout<<"renderercreated"<<std::endl;
        }
        isRunning = true;

    }
    else isRunning = false;
    SDL_Surface *tmpSurface = IMG_Load("resource/mainchar.png");
    mCharacterTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
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
    cnt++;
    destR.h=64;
    destR.w=32;
    destR.x=+cnt/10;
    destR.y=+cnt/10;
    std::cout<<cnt<<std::endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,mCharacterTex,NULL, &destR);
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"gamecleaned"<<std::endl;
}
