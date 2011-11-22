#include <SDL/SDL.h>
#include <iostream>
#include <string>

#include "Tile.h"

Tile::Tile()
{
    Image blank("small.bmp");
    setTileWalkable(false);
    setTileImage(blank);
    setXPos(-1);
    setYPos(-1);
}

Tile::Tile(Image image, bool walkable)
{
    std::cout << "In Constructor Tile(Image image, bool walkable)...\n"
    << "Setting tile as walkable...\n";
    setTileWalkable(walkable);
    std::cout << "Success!\n"
    << "Setting image to this tiles image...\n";
    setTileImage(image);
    std::cout << "Success!\n"
    << "Setting both the X and Y position to -1\n";
    setXPos(-1);
    setYPos(-1);
    std::cout << "Success!\nLeaving Constructor2" << endl;
}

Tile::Tile(Image image, bool walkable, int x, int y)
{
    setTileWalkable(walkable);
    setTileImage(image);
    setXPos(xPos);
    setYPos(yPos);
}

Tile::~Tile()
{
}

void Tile::setTileImage(Image image)
{
    graphic = &image;
}

void Tile::setTileWalkable(bool walk)
{
    walkable = walk;
}

void Tile::setXPos(int pos)
{
    xPos = pos;
}

void Tile::setYPos(int pos)
{
    yPos = pos;
}

Image Tile::getTileImage()
{
    return *graphic;
}

bool Tile::getWalkable()
{
    return walkable;
}

int Tile::getXPos()
{
    return xPos;
}

int Tile::getYPos()
{
    return yPos;
}

void Tile::drawTile(SDL_Surface *surfDest, int destX, int destY)
{
    SDL_Rect destRec;
    destRec.x = destX;
    destRec.y = destY;

    SDL_BlitSurface(getTileImage().getSurface(), &getTileImage().getRect(), surfDest, &destRec);
    SDL_UpdateRect(surfDest, 0,0,0,0);
}

