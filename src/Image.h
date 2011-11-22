#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>
#include <string>

#define STDTILE 50    //This is the default size for a tile
#define STDCKEY 255   //This is the default color key.  It is specific to green if I can help it.

class Image
{
    public:

    //Load an entire image into memory with all defaults if any
    Image(std::string filename); 
    //Load a part of an image into memory.  Specified position, default tilsize, default colorkey
    Image(std::string filename, int xPos, int yPos); 
    //Load part of an image in memory.  Specified position, specified tilesize, specified colorkey
    Image(std::string filename, int xPos, int yPos, int width, int height, int rkey, int gkey, int bkey);

    //Destructor.  Frees all the surfaces and stuff.  
    ~Image();

    void setSurface(std::string filename); //Loads a surface into memory.  This is the function that just does that.
    void setRect(); //Creates a rectangle for a nonspecific image size.
    void setRect(int xPos, int yPos, int width, int height); //Create a rectangle for the image.
    void setTileSize(int width, int height); //Sets the size of the tile. Negative values don't change the default size.
    void setColorKey(int r, int g, int b); //Takes three integers and creates a colorkey

    SDL_Surface* getSurface(); //Returns the surface where the image lives
    SDL_Rect getRect(); //Returns the rectangle that the image has
    int getWidth(); //Returns the images width
    int getHeight(); //Returns the images hight
    Uint32 getColorKey(); //Returns the colorkey Uint32
    Image* getImage(); //Returns this whole image object

    //Draws the entire image the the scree.  Used mostly for testing purposes.
    //Accepts the surface to draw to and the place on the new surface to draw to.
    void drawImage(SDL_Surface *surfDest, bool useCKey, int destX, int destY); 

    private:

    SDL_Surface *surf; //Stores surface
    SDL_Rect rect; //Stores the rectangle
    int width, height; 
    Uint32 colorKey;


};

#endif

