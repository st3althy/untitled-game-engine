#ifndef MAP_H
#define MAP_H

#include <string>

#include "Tile.h"

class Map
{
    public:
    Map(Tile map[], std::string name, int height, int width);

    void setMapName(std::string name);
    void setMapHeight(int height);
    void setMapWidth(int width);
    void setMap(Tile map[]);

    std::string getMapName();
    int getMapHeight();
    int getMapWidth();
    Tile* getMap();

    void drawMap();

    private:
    std::string mapName;
    int mapHeight;
    int mapWidth;
    Tile map[];
};
#endif

