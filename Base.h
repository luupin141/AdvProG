#ifndef BASE_H_
#define BASE_H_

#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

//game stats
const int SCR_WID = 1024;
const int SCR_HEI = 640;
const int SCR_BPP = 32;

const int CLK_R = 0;
const int CLK_G = 255;
const int CLK_B = 255;


static SDL_Window* mWindow = NULL;
static SDL_Renderer* mRenderer = NULL;
static SDL_Event mEvent ;

#define BLOCK_SIZE 32
#define MAP_HEI 20
#define MAP_WID 70

typedef struct Map
{
    int start_x_;
    int start_y_;

    int stt_x_;
    int stt_y_;

    int block[MAP_HEI][MAP_WID];
    char * file_name;
};


#endif
