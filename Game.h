#ifndef Game_h
#define Game_h

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>


const int gHeight= 320;
const int gWidth = 640;

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

    static void addTile(int x, int y, int id);
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
private:

    bool isRunning;
    SDL_Window *window;


};

#endif // Game_hpp
