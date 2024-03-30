#ifndef Map_h
#define Map_h

#include"Game.h"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(int arr[10][15]);
    void DrawMap();
private:
    SDL_Rect src,dest;
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* dirt;
    int map[10][15];

};

#endif // Map_h
