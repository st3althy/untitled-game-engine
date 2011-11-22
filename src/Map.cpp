#include <SDL/SDL.h>

#include "Map.h"

Map::Map(Tile m[], std::string name, int height, int width)
{
    setMap(m);
    setMapName(name);
    setMapHeight(height);
    setMapWidth(width);
}

void Map::setMapName(std::string name)
{
    mapName = name;
}

void Map::setMapHeight(int height)
{
    mapHeight = height;
}

void Map::setMapWidth(int width)
{
    mapWidth = width;
}

void Map::setMap(Tile m[])
{
    map = &m;
}

std::string Map::getMapName()
{
    return mapName;
}

int Map::getMapHeight()
{
    return mapHeight;
}

int Map::getMapWidth()
{
    return mapWidth;
}

Tile* Map::getMap()
{
    return map;
}

void Map::drawMap(SDL_Surface *surfDest)
{
    int tiles = height * width;
    int count = 0;
    for(int i = 0; i < tiles; i++)
    {
        if(count < width)
        {
            map[i].drawTile(surfDest,(count
        }
    }
}

