#include "Base.h"
#include "Object.h"
#include "Map.h"

Object _background;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0) return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    mWindow = SDL_CreateWindow("luu",
                               int SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               SCR_WID,
                               SCR_HEI,
                               SDL_WINDOW_SHOWN);
    if(mWindow == NULL)
    {
        success = false;
    }
    else
    {
        mRenderer = SDL_CreateRenderer(mWindow,-1,SDL_RENDERER_ACCELERATED);
        if(mRenderer == NULL)
            success = false;
        else {
            SDL_SetRenderDrawColor(mRenderer,CLK_R, CLK_G, CLK_B, 255);
            int imgFlag = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlag)&&imgFlag))
                success = false;
        }
    }
    return success;
}
bool LoadBackground()
{
    bool ret = _background.LoadImg("background.png", mRenderer);
    if (!ret) return false;
    return true;
}

void close()
{
    _background.Free();

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char * argv[])
{

    if(!InitData()) return -1;
    if(!LoadBackground()) return -1;
    GameMap gMap;
    gMap.LoadMap("map.dat");
    gMap.LoadTiles(mRenderer);
    bool quit = false;
    while (!quit)
    {
        while(SDL_PollEvent(&mEvent)!=0)
        {
            if(mEvent.type == SDL_QUIT) quit = true;
        }
        SDL_SetRenderDrawColor(mRenderer,CLK_R, CLK_G, CLK_B, 255);
        SDL_RenderPresent(mRenderer);

        _background.Render(mRenderer, NULL);
        gMap.DrawMap(mRenderer);
        SDL_RenderPresent(mRenderer);

    }
    close();

    return 0;
}
