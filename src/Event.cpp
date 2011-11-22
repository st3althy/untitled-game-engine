#include <iostream>
#include "Menu.h"
#include "Tile.h"
#include "Option.h"
#include <SDL/SDL.h>
void Event::onKeyPress(Uint8 *keys, Tile tile, Player player){
	if(keys[SDLK_UP] && tile.isWalkable()) player.posx -= 1;
	if(keys[SDLK_DOWN] && tile.isWalkable()) player.posx += 1;
	if(keys[SDLK_LEFT] && tile.isWalkable()) player.posy -= 1;
	if(keys[SDLK_RIGHT] && tile.isWalkable()) player.posy += 1;
}

void Event::onPlayerInteract(Uint8 *keys, Player other, Player you){
	int done = 0;
	while(done == 0){
		if((done = other.talk(keys)) == 1){
			other.exitConv();
			you.exitConv();
		}
		if((done = you.talk(keys)) == 1){
			you.exitConv();
			exit.exitConv();
		}
		keys = SDL_GetKeyState(NULL);
	}
}

void Event::onPause(Uint8 *keys, Menu m){
	m = new Menu();
	m.drawMenu();
	bool paused == true;
	while(paused){
		m.select(keys);
		if(keys[SDLK_ESCAPE]){
			onResume();
			paused = false;
		}
		keys = SDL_GetKeyState(NULL);
	}
}

void Event::onResume(Menu m){
	m.clearMenu();
}

void Event::onMenuSelect(Menu m, Unit8 *keys){
	m.openMenu();
	m.select(keys);
}

void Event::onOptionSelect(Option o){
	o.setOption();
	o.backtoMenu();
}
