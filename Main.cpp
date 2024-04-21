#include "Game.h"
#include "ECS.h"
#include "Components.h"

#include"string"
#undef main


Game *game = nullptr;
const int FPS = 45;//adjust framerate
const int frameDelay = 1000/FPS;
Uint32 frameStart;
int frameTime;



int main(int argc, const char ** argv)
{
    game = new Game();
    game->init("X", gWidth, gHeight, SDL_WINDOW_SHOWN);//initialize



    //game loop
    while(game->running()){

        frameStart = SDL_GetTicks();


        game->handleEvent();
        game->update();
        game->render();

        frameTime = SDL_GetTicks()-frameStart;

        if(frameDelay>frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }

    }
    game->clean();
    return 0;
}
