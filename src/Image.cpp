#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

#include "Image.h"

Image::Image(std::string filename)
{
    setSurface(filename); //Loads entire image into memory
    setRect(); //Load entire image into rectangle
    setTileSize(surf->w, surf->h); //Sets tilesize using the entire image size
    setColorKey(0,0,0); //No colorkey
}

Image::Image(std::string filename, int xPos, int yPos)
{
    setSurface(filename); //Loads entire image into memory
    setRect(xPos, yPos, STDTILE, STDTILE); //Loads part of image specified by x and y position.  Standard tilesize
    setTileSize(STDTILE, STDTILE); //Uses the default tilesize
    setColorKey(0,0,STDCKEY); //Uses the default colorkey
}

Image::Image(std::string filename, int xPos, int yPos, int width, int height, int rkey, int gkey, int bkey)
{
    setSurface(filename);
    setRect(xPos, yPos, width, height);
    setTileSize(width, height);
    setColorKey(rkey, gkey, bkey);
}

Image::~Image()
{
    SDL_FreeSurface(surf);
}

void Image::setSurface(std::string filename)
{
    surf = SDL_LoadBMP(filename.c_str());
    if(surf == NULL)
    {
        std::cout << "Unable to load image: " << filename << std::endl;
        //Eventually come up with some default cannot load image
    }
}

void Image::setRect()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = surf->w;
    rect.h = surf->h;
}

void Image::setRect(int xPos, int yPos, int w, int h)
{
    rect.x = xPos;
    rect.y = yPos;
    rect.w = w;
    rect.h = h;
}

void Image::setTileSize(int w, int h)
{
    if(w > 0)
    {
        width = w;
    }
    if(h > 0)
    {
        height = h;
    }
    else
    {
        std::cout << "Tilesize probably shouldn't be zero..." << std::endl;
    }
}

void Image::setColorKey(int r, int g, int b)
{
    colorKey = SDL_MapRGB(surf->format, r, g, b);
}

SDL_Surface* Image::getSurface()
{
    return surf;
}

SDL_Rect Image::getRect()
{
    return rect;
}

int Image::getWidth()
{
    return width;
}

int Image::getHeight()
{
    return height;
}

Uint32 Image::getColorKey()
{
    return colorKey;
}

Image* Image::getImage()
{
    return this;
}

void Image::drawImage(SDL_Surface* surfDest, bool useCKey, int destX, int destY)
{
    SDL_Rect destRect;
    if(useCKey)
    {
        SDL_SetColorKey(getSurface(), SDL_SRCCOLORKEY, getColorKey());
    }
    else
        SDL_SetColorKey(getSurface(), 0, getColorKey());

    destRect.x = destX;
    destRect.y = destY;

    SDL_BlitSurface(getSurface(), &getRect(), surfDest, &destRect);
    SDL_UpdateRect(surfDest, 0,0,0,0);
}

