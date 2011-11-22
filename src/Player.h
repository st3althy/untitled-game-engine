#include "Image.h"
#include "Tile.h"
#include <SDL/SDL.h>
#include <iostream>
using namespace std;
class Player{
	private:
	SDL_Surface *surf;
	SDL_Rect rec;
	int widht, height;
	public:
	int posx, int posy;
	Player(string fname, int x, int y);//new Player at specified position
	Player(string fname, int x, int y, int w, int h);//same as above but with specified widht and height
	Player(string fname, int x, int y, int w, int h, int rk, int bk, int gk);//same as above with specified Ckey
	~Player();//destructor
	void talk();
	void exitConv();
	int getX();
	int getY();
	int getW();
	int getH();
	void drawChar(SDL_Surface *map);
}
