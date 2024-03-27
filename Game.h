#ifndef Game_hpp
#define Game_hpp

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
class Game
{
public:
    Game();
    ~Game();

    void init(const char* title,int posx, int posy, int width, int height, bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}
private:
    int cnt=0;
    bool isRunning ;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif // Game_hpp
