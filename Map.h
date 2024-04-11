#ifndef Map_h
#define Map_h
#include"string"
#include"Game.h"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);

};

#endif // Map_h
