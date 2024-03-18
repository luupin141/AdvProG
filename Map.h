#ifndef MAP_H_
#define MAP_H_

#include "Base.h"
#include "Object.h"
#define TILE_NUM 10
class Tiled : public Object
{
public :
    Tiled(){;}
    ~Tiled(){;}
};

class GameMap
{
public :
    GameMap(){;}
    ~GameMap(){;}
    void LoadMap(char* path);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);
private :
     Map _map;
     Tiled _tiles[TILE_NUM];

};

#endif // MAP_H_
