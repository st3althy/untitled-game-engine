#ifndef TILE_H
#define TILE_H

#include "Image.h"
//#include "EventList.h"

class Tile
{
    public:
    //Default Tile.  Everything is blank.
    Tile();
    //Creates a tile with some image and sets whether or not it is walkable.  Tile has no position.
    Tile(Image graphic, bool walkable);
    //Creates a tile with some image and sets whether or not it is walkable.  Tile has position.
    Tile(Image graphic, bool walkable, int xPos, int yPos);
    //Destructor.  nuff said
    ~Tile();

    //Sets the tiles image
    void setTileImage(Image image);
    //Sets whether or not the tile is walkable
    void setTileWalkable(bool walk);
    //Sets the x position of the tile
    void setXPos(int x);
    //Sets the y position of the tile
    void setYPos(int y);

    //Gets the tiles image
    Image getTileImage();
    //Gets whether or not the tile is walkable
    bool getWalkable();
    //Gets the x position of the tile
    int getXPos();
    //Gets the y position of the tile
    int getYPos();

    //Draws the tile to the surface specified at the specified Position
    void drawTile(SDL_Surface *surfDest, int destX, int destY);

    private:
    bool walkable;
    Image *graphic;
    int xPos, yPos;
};

#endif

