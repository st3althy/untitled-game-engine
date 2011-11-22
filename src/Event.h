#include <iostream>
#include "Menu.h"
#include "Tile.h"
#include "Option.h"
#include "Player.h"
class Event{
	public:
	void onKeyPress(Uint8 *keys, Tile tile, Player player);
	void onplayerInteract(Uint8 *keys, Player other);
	void onPause(Uint8 *keys, Menu m);
	void onResume(Menu m);
	void onMenuSelect(Menu m, Unint8 keys);
	void onOptionselect(Option o);
};
