#include "Map.h"
#include "Textures.h"
#include "iostream"
int lvl1[10][15] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
    {0,0,0,2,2,2,2,2,2,0,0,0,2,0,0},
    {0,2,2,2,2,1,1,1,2,2,1,1,0,0,0},
    {0,2,2,2,0,1,1,1,2,1,2,1,0,0,0},
    {0,0,1,1,0,0,1,0,1,2,2,1,0,0,0},
    {0,0,1,1,0,0,2,0,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
Map::Map()
{
    dirt = TextureManage::LoadTexture("dirt.png");
    grass = TextureManage::LoadTexture("grass.png");
    water = TextureManage::LoadTexture("water.png");
    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;

}
Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(water);
}

void Map::LoadMap(int arr[10][15])
{
    for (int row=0;row<10;row++ )
    {
        for( int col = 0; col<15;col++){
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap(){
    int type = 0 ;
    for (int row=0; row<10 ; row++){
        for(int col=0; col<15;col++){
            type = map[row][col];

            dest.x = col * 32;
            dest.y = row * 32;

            switch(type)
            {
                case 0 :
                    TextureManage::Draw(water,src,dest);
                    break;
                case 1:
                    TextureManage::Draw(dirt,src,dest);
                    break;
                case 2:
                    TextureManage::Draw(grass,src,dest);
                    break;

                default: break;
            }
        }
    }
}
