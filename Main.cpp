#include "Game.h"
#undef main
Game *game = nullptr;

int main(int argc, const char ** argv)
{

    game = new Game();
    game->init("X", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    while(game->running()){
        game->handleEvent();
        game->update();
        game->render();
    }
    game->clean();
    return 0;

}
