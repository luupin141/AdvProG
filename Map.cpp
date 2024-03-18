#include"Map.h"

#include "stdio.h"
#include "fstream"
void GameMap::LoadMap(char * path) {
    std::ifstream file(path, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Failed to open the file!" << std::endl;
        return;
    }

    for (int i = 0; i < MAP_HEI; i++) {
        for (int j = 0; j < MAP_WID; j++) {
            int val;
            file >> val;
            _map.block[i][j] = val;

            if (val > 0) {
                if (j > _map.stt_x_)
                    _map.stt_x_ = j;
                if (i > _map.stt_y_)
                    _map.stt_y_ = i;
            }
        }
    }

    _map.stt_x_ = (_map.stt_x_ + 1) * BLOCK_SIZE;
    _map.stt_y_ = (_map.stt_y_ + 1) * BLOCK_SIZE;
    _map.start_x_ = 0;
    _map.start_y_ = 0;
    _map.file_name = path;

    file.close();
}
void GameMap::LoadTiles(SDL_Renderer *screen)
{
    char file_img[10];

    for(int i = 0; i < TILE_NUM; i++)
    {
        snprintf(file_img, sizeof(file_img), "map/%d.png", i);

        std::ifstream file_stream(file_img, std::ios::binary);
        if (!file_stream.is_open())
        {
            continue;
        }

        file_stream.close();
        _tiles[i].LoadImg(file_img, screen);
    }
}
void GameMap::DrawMap(SDL_Renderer* screen)
{
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = _map.start_x_/BLOCK_SIZE;
    x1 = (_map.start_x_%BLOCK_SIZE)*-1;
    x2 = x1 + SCR_WID + (x1 == 0 ? 0 : BLOCK_SIZE);
    map_y = _map.start_y_/BLOCK_SIZE;
    y1 = (_map.start_y_%BLOCK_SIZE)*-1;
    y2 = y1 + SCR_HEI + (y1 == 0 ? 0 : BLOCK_SIZE);

    for (int i=y1; i< y2; i+= BLOCK_SIZE)
    {
        map_x = _map.start_x_/BLOCK_SIZE;
        for (int j=x1; j<x2; j+= BLOCK_SIZE)
        {
            int val = _map.block[map_y][map_x];
            if(val>0)
            {
                _tiles[val].SetRect(j,i);
                _tiles[val].Render(screen);
            }
            map_x++;
        }
        map_y++;
    }
}
