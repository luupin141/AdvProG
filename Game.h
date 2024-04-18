#ifndef Game_h
#define Game_h
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<bits/stdc++.h>

const int gHeight= 640;
const int gWidth = 1280 ;

class ColliderComponent;


class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}



    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
private:

    bool isRunning;
    SDL_Window *window;



};

#endif // Game_hpp
